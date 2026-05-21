//https://codefun2000.com/p/P4626


#include <bits/stdc++.h>
using namespace std;

struct Node{
    double x;
    double y;
    double z;
    int id;
};

double distance(double x1,double y1,double z1,double x2,double y2,double z2){
    return pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2);
}

int main(){
    int k, n;
    cin >> n >> k;

    //使用结构体来高效收集相关数据
    vector<Node> dataset;
    for (int i = 0; i < n;i++){
        double a, b, c;
        int id;
        cin >> a >> b >> c >> id;
        dataset.push_back({a, b, c, id});
    }
    
    //输入判断核心进行分析
    double x_core, y_core, z_core;
    cin >> x_core >> y_core >> z_core;

    //使用pair的将label和dis结合
    vector<pair<double,int>> arr;
    for (int i = 0;i<n;i++){
        Node P = dataset[i];
        double dis = distance(P.x, P.y, P.z, x_core, y_core, z_core);
        int id = P.id;
        arr.push_back({dis, id});
    }
    sort(arr.begin(), arr.end());

    int count = 0;
    unordered_map<int,int> ans;
    for (auto& opt:arr){
        int opt_id = opt.second;

        auto ita = ans.find(opt_id);
        if(ita==ans.end())
            ans[opt_id] = 1;
        else

        
            ans[opt_id]++;
        count++;
        if(count==k)
            break;
    }

    int max_len = -1;
    int ans_k = -1;

    for(auto& pr:ans){
        if(pr.second>=max_len){
            max_len = pr.second;
            ans_k = pr.first;
        }
    }
    
    cout << ans_k << endl;
    return 0;
}