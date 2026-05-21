#include<bits/stdc++.h>
using namespace std;

const double INF = 1e9;

struct Node{
    double x;
    double y;
    double dis2;
    double dis;
    int k;
};

//银行家处理位置：
//在进行处理的时候要保留两位小数，在C语言中直接实现
double r(double d){
    const int S = 100;
    int n = (int)(S * d);
    double ans = (double)n;
    if(n+0.5>d*S)
        return ans/S;
    else if(n+0.5<d)
        return (ans+1) / S;
    else{
        if(n%2==0)
            return ans / S;
        else
            return (ans + 1) / S;
    }
}

double dist2(double x1,double y1,double x2,double y2){
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

double dist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}



int main(){
    int n, k;
    cin >> n >> k;

    vector<Node> nodes;
    vector<pair<double,double>> cores;//KMeans核心位置

    //读取相关点阵信息，初始化簇中点位置
    for (int i = 0; i < n;i++){
        double x_in;
        double y_in;
        cin >> x_in >> y_in;
        Node p;
        p.x = x_in;
        p.y = y_in;

        nodes.push_back(p);
        if(i<k){
            cores.push_back({x_in, y_in});
        }
    }

    vector<vector<int>> core_scale;
    core_scale.reserve(k + 1);
    //用来说明每一个聚类中心中有多少的点；

    for (int i = 1; i <= 100;i++){
        //遍历对于所有点的位置,循环的次数就是聚类的次数
        double min_dis = INF;
        double ans_k = -1;

        //求出当前点对于那一个聚类中心最接近，并且记录所有聚类中拥有的点数的数量
        for (int j = 0; j < k;j++){
            double x1 = nodes[j].x;
            double y1 = nodes[j].y;

            double x2 = cores[j].first;
            double y2 = cores[j].second;

            double disc2 = dist2(x1, y1, x2, y2);
            if(min_dis>disc2){
                min_dis = disc2;
                ans_k = j;
                //对于每一个点存储所有的数据
                core_scale[ans_k].push_back(j);
            }
        }

        double min_dis = INF;
        //遍历所有的聚类，计算出更新之后的聚类中心
        for (int j = 0; j < k;j++){
            //用来统计所有点的总和；
            double x_new, y_new, x_sum, y_sum;
            x_sum = 0.0;
            y_sum = 0.0;
            if(core_scale[j].empty()){
                continue;
            }
            else{
                for (int k = 0; k < core_scale[j].size();k++){
                    int k_node = core_scale[j][k];
                    x_sum += nodes[k_node].x;
                    y_sum += nodes[k_node].y;
                }
            }
            x_new = x_sum * 1.0 / core_scale[j].size();
            y_new = y_sum * 1.0 / core_scale[j].size();
            
            //记录这一步KMean的时候，我们所找到的聚类核心最小移动值；
            double dis=dist(cores[k].first,cores[k].second,x_new,y_new);
            min_dis = min(min_dis, dis);
            cores[k].first=x_new;
            cores[k].second = y_new;
        }
        if(min_dis<1e-6)
            break;
    }

    
}