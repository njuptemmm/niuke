#include <bits/stdc++.h>
using namespace std;

static inline double dist2(double x1,double y1,double x2,double y2){
    double dx=x1-x2, dy=y1-y2; return dx*dx+dy*dy;
}
static inline double dist(double x1,double y1,double x2,double y2){
    return hypot(x1-x2, y1-y2);
}

// 银行家舍入到两位
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

    // K-Means：前 k 个点为初始中心
    vector<double> cx(k), cy(k);
    for(int c=0;c<k;c++){ cx[c]=x[c]; cy[c]=y[c]; }
    vector<int> lab(n);

    for(int it=0; it<100; ++it){
        // 分配
        for(int i=0;i<n;i++){
            int bi=0; double bd=dist2(x[i],y[i],cx[0],cy[0]);
            for(int c=1;c<k;c++){
                double d=dist2(x[i],y[i],cx[c],cy[c]);
                if(d<bd){ bd=d; bi=c; }
            }
            lab[i]=bi;
        }
        // 更新
        vector<double> sx(k,0), sy(k,0); vector<int> cnt(k,0);
        for(int i=0;i<n;i++){ int c=lab[i]; sx[c]+=x[i]; sy[c]+=y[i]; cnt[c]++; }
        double moved=0;
        for(int c=0;c<k;c++){
            double nx=cx[c], ny=cy[c];
            if(cnt[c]>0){ nx=sx[c]/cnt[c]; ny=sy[c]/cnt[c]; }
            moved += fabs(nx-cx[c])+fabs(ny-cy[c]);
            cx[c]=nx; cy[c]=ny;
        }
        if(moved<=1e-6) break;
    }

    // 轮廓系数
    vector<vector<int>> g(k);
    for(int i=0;i<n;i++) g[lab[i]].push_back(i);
    vector<double> sil(k,0.0);
    for(int c=0;c<k;c++){
        if(g[c].empty()) { sil[c]=0; continue; }
        double sum=0;
        for(int id: g[c]){
            double a=1.0;
            if(g[c].size()>1){
                a=0;
                for(int j: g[c]) if(j!=id) a += dist(x[id],y[id],x[j],y[j]);
                a /= (int)g[c].size()-1;
            }
            double b = numeric_limits<double>::infinity();
            for(int c2=0;c2<k;c2++){
                if(c2==c || g[c2].empty()) continue;
                double t=0;
                for(int j: g[c2]) t += dist(x[id],y[id],x[j],y[j]);
                b = min(b, t/(int)g[c2].size());
            }
            double s = isinf(b)?0:((max(a,b)==0)?0:(b-a)/max(a,b));
            sum += s;
        }
        sil[c] = sum / (int)g[c].size();
    }

    int bad=0;
    for(int c=1;c<k;c++) if(sil[c]<sil[bad]) bad=c;
    cout<<r2(cx[bad])<<","<<r2(cy[bad])<<"\n";
    return 0;
}
/*
程序设计代码总结：
1.我们可以发现相关的points其实只有在最开始的时候进行使用
2.这个KMeans算法中仅仅在g[]中间的部分使用的是二维数组，用来存储聚类和点的关系，
3.
*/