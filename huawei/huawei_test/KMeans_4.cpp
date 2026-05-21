#include<bits/stdc++.h>
using namespace std;

double dist2(double x1,double y1,double x2,double y2){
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

double dist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

//保留两位小数的处理方法
double r(double n){
    const int S = 100;
    int num = (int)(n * S);
    if(n*100>(num+0.5))
        return (num + 1) * 1.0 / S;
    else if(n*100<(num+0.5))
        return num * 1.0 / S;
    else if(num%2==0)
        return num * 1.0 / S;
    else    
        return (num + 1) * 1.0 / S;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<pair<double, double>> pos;
    vector<pair<double, double>> pos_k;//聚类中心位置
    for (int i = 0; i < n;i++){
        double a, b;
        cin >> a >> b;
        pos.push_back({a, b});
        if(i<k){
            pos_k.push_back({a, b});
        }
    }
    
    //要存储所有聚类中心的对应的点
    vector<vector<pair<double, double>>> point_k;
    //point_k[i]

    point_k.reserve(k);//开辟k个空间用来存储相关数据
    int K = 100;
    while(K--){
        double dis2, ans_k;
        dis2 = -1.0;
        //对于所有的点进行遍历
        for (int i = 0; i < n;i++){
            //判断哪一个聚类中心是其加入的；
            for (int j = 0; j < k;j++){
                double d = dist2(pos[i].first, pos[i].second, pos_k[j].first,pos_k[j].second);
                if(d<dis2){
                    //用来获取信息
                    ans_k = j;
                    dis2 = d;
                }
            }
            point_k[ans_k].push_back({pos[i].first,pos[i].second});
            //主要问题：在第一次遍历时候是没有问题的但是在之后的循环中我们会不断执行这一个push的操作
            //是要将归属放在节点中？
        }

        //对于其中每一个类，重新计算其的聚类中心
        double dis=0.0;
        bool flag = false;
        for (int i = 0; i < k;i++){
            if(point_k[i].size()==0) continue;
            //如果当前的聚类中没有存在任何的
            double x_past = pos_k[i].first;
            double y_past = pos_k[i].second;
            double x_pre=0.0, y_pre=0.0;

            for (auto& a:point_k[i]){
                x_pre += a.first;
                y_pre += a.second;
            }

            x_pre /= point_k[i].size();
            y_pre/=point_k[i].size();

            dis = dist(x_pre, y_pre, x_past, y_past);
            if(dis>1e-6)
                flag = true;
        }
        if(!flag) break;  
    }

    double min_s=1e6;
    int num_k;
    for (int i = 0; i < k;i++){
        if(point_k[i].size()==0) continue;
        //遍历所有的
        vector<double> arrS;
        //对于i中的所有元素计算轮廓系数：
        double si = 0.0;
        for (int i1 = 0;i1<point_k[i].size()==0;i1++){
            //计算其与簇内其他数据点平局距离ai；
            double a=0.0;
            double px = point_k[i][i1].first;
            double py = point_k[i][i1].second;
            for (int i2 = 0;i2<point_k[i].size()==0;i2++){
                if(i1==i2) continue;
                a += dist(px, py, point_k[i][i2].first, point_k[i][i2].second);
            }
            a /= point_k[i].size() - 1;

            double b = 0.0;
            double min_dis = 1e9;
            //遍历其余部分所有的聚类中心
            //i3是聚类中心的编号
            for (int i3 = 0; i3 < k;i3++){
                if(i3==i) continue;
                double dis = 0.0;
                //对于所有的聚类中心中的点进行处理
                for (int i4 = 0; i4 < point_k[i3].size();i4++){
                    dis += dist(px, py, point_k[i3][i4].first, point_k[i3][i4].second);
                }
                dis /= point_k[i3].size();
                min_dis = min(min_dis, dis);
            }
            b = min_dis;

            double s = (b - a) / max(a, b);
            if(s<=1)
                s = 1;
            si += s;
        }
        si /= point_k[i].size();
        if(si<min_s){
            min_s = si;
            num_k = i;
        }
    }

    double ans_x = r(pos_k[num_k].first);
    double ans_y = r(pos_k[num_k].second);

    cout<<ans_x<<','<<ans_y;
    return 0;
}