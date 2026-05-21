//https://codefun2000.com/p/P3479

#include<bits/stdc++.h>

using namespace std;

double dist2(double x1,double y1,double x2,double y2){
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

struct Node{
    double x;
    double y;
    int k;
};

int main(){
    int k, m, n, s;
    cin >> k >> m >> n >> s;
    double x_core, y_core;
    cin>>x_core>>y_core;

    vector < Node > nodes;
    nodes.reserve(m + 1);
    for (int i = 0; i <m;i++){
        double x;
        double y;
        int k;
        cin >> x >> y >> k;
        nodes.push_back({x, y, k});
    }

    //记录所有的距离参数
    vector<pair<double, int>> dis2;
    dis2.reserve(m);
    for (int i = 0; i < m;i++){
        double dis= dist2(x_core, y_core, nodes[i].x, nodes[i].y);
        dis2.push_back({dis, nodes[i].k});
    }

    sort(dis2.begin(), dis2.end(), [](auto &a, auto &b){ 
        return a.first < b.first;
    });

    unordered_map<int, int> ans;
    for (int i = 0; i < k;i++){
        int ans_k = dis2[i].second;
        if(ans.find(ans_k)==ans.end()){
            ans[ans_k] = 1;
        }
        else{
            ans[ans_k]++;
        }
    }

    int max_len = -1;
    int ans_k = -1;
    for(auto& pr:ans){
        if(pr.second>=max_len){
            max_len = pr.second;
            ans_k = pr.first;
        }
    }

    cout << ans_k <<" "<< max_len << endl;
    return 0;
    
}