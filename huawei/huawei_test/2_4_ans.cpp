/*
 * 题意概要（K-Means + 轮廓系数）：
 * 1) 用前 k 个样本作为初始聚类中心，迭代「分配 → 更新中心」，
 *    最多 100 轮，或各中心在 x/y 上移动量之和 <= 1e-6 时停止。
 * 2) 按最终划分计算每个簇的轮廓系数：簇内各点 s_i 的算术平均；
 *    s_i = (b_i - a_i) / max(a_i, b_i)，题面单点簇时该点 s=1。
 * 3) 选出轮廓系数最小的簇，输出其中心坐标；
 *    保留两位小数，舍入方式为 HALF_EVEN（银行家舍入）。
 */
#include <bits/stdc++.h>
using namespace std;

// 欧氏距离平方：仅用于「找最近中心」，与比较真实距离大小等价，且避免开方。
static inline double dist2(double x1,double y1,double x2,double y2){
    double dx=x1-x2, dy=y1-y2; return dx*dx+dy*dy;
}
// 欧氏距离：轮廓系数 a_i、b_i 按题意用真实距离。
static inline double dist(double x1,double y1,double x2,double y2){
    return hypot(x1-x2, y1-y2);
}

// 将 v 四舍五入到两位小数（HALF_EVEN）：先放大 100 倍，若小数部分恰为 0.5 则向偶数取整。
// EPS 用于缓解浮点误差；再格式化为字符串，避免 printf 默认舍入与题意不一致。
string r2(double v){
    long double s = (long double)v * 100.0L;
    long double f = floor(s);
    long double frac = s - f;
    const long double EPS = 1e-12L;
    long long u;
    if(frac > 0.5L + EPS) u = (long long)f + 1;
    else if(frac < 0.5L - EPS) u = (long long)f;
    else u = ((long long)f % 2 == 0) ? (long long)f : (long long)f + 1;
    long long ip = u / 100, fp = llabs(u % 100);
    ostringstream os; os<<ip<<'.'<<setw(2)<<setfill('0')<<fp; return os.str();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; if(!(cin>>n>>k)) return 0;
    vector<double> x(n), y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    // K-Means：前 k 个点为初始聚类中心（题面规定）。
    vector<double> cx(k), cy(k);
    for(int c=0;c<k;c++){ cx[c]=x[c]; cy[c]=y[c]; }
    vector<int> lab(n);

    for(int it=0; it<100; ++it){
        // 分配：每个点归到距离平方最小的簇（与最近欧氏距离等价）。
        for(int i=0;i<n;i++){
            int bi=0; double bd=dist2(x[i],y[i],cx[0],cy[0]);
            for(int c=1;c<k;c++){
                double d=dist2(x[i],y[i],cx[c],cy[c]);
                if(d<bd){ bd=d; bi=c; }
            }
            lab[i]=bi;
        }
        // 更新：簇内坐标均值作为新中心；空簇则保持原中心不变。
        vector<double> sx(k,0), sy(k,0); vector<int> cnt(k,0);
        for(int i=0;i<n;i++){ int c=lab[i]; sx[c]+=x[i]; sy[c]+=y[i]; cnt[c]++; }
        double moved=0;
        for(int c=0;c<k;c++){
            double nx=cx[c], ny=cy[c];
            if(cnt[c]>0){ nx=sx[c]/cnt[c]; ny=sy[c]/cnt[c]; }
            // 题意终止条件：各中心在 x、y 方向位移绝对值之和（非欧氏一步距离）。
            moved += fabs(nx-cx[c])+fabs(ny-cy[c]);
            cx[c]=nx; cy[c]=ny;
        }
        if(moved<=1e-6) break;
    }

    // 轮廓系数：g[c] 为簇 c 内的点下标；sil[c] 为该簇内所有点 s_i 的平均值。
    vector<vector<int>> g(k);
    for(int i=0;i<n;i++) g[lab[i]].push_back(i);
    vector<double> sil(k,0.0);
    for(int c=0;c<k;c++){
        if(g[c].empty()) { sil[c]=0; continue; }
        double sum=0;
        for(int id: g[c]){
            // a：与同簇其它点的平均距离；簇内仅一点时题面规定 s=1，此处 a 取 1 与之对应。
            double a=1.0;
            if(g[c].size()>1){
                a=0;
                for(int j: g[c]) if(j!=id) a += dist(x[id],y[id],x[j],y[j]);
                a /= (int)g[c].size()-1;
            }
            // b：到「每一个其它簇」的平均距离，再对所有其它簇取最小。
            double b = numeric_limits<double>::infinity();
            for(int c2=0;c2<k;c2++){
                if(c2==c || g[c2].empty()) continue;
                double t=0;
                for(int j: g[c2]) t += dist(x[id],y[id],x[j],y[j]);
                b = min(b, t/(int)g[c2].size());
            }
            // s_i = (b-a)/max(a,b)；无有效其它簇时 b 仍为 inf，记 s=0。
            double s = isinf(b)?0:((max(a,b)==0)?0:(b-a)/max(a,b));
            sum += s;
        }
        sil[c] = sum / (int)g[c].size();
    }

    // 轮廓系数最小的簇（并列时取编号更小者，因从下标 1 起用严格 < 更新）。
    int bad=0;
    for(int c=1;c<k;c++) if(sil[c]<sil[bad]) bad=c;
    cout<<r2(cx[bad])<<","<<r2(cy[bad])<<"\n";
    return 0;
}
