#include<bits/stdc++.h>
using namespace std;

const int S = 100;//对于其中涉及到所有精度的问题进行放大避免精度问题
const int INF = 1e9;

int main(){
    int L;
    double T;
    cin >> L >> T;
    T *= S;
    vector<vector<pair<double, double>>> opts;
    opts.resize(L+1);

    for (int i = 1; i <= L;i++){
        int k;
        cin>>k;
        for (int j = 1; j <= k;j++){//遍历每一个选择
            string s1;
            double loss,mem;
            cin >> s1 >> loss >> mem;
            loss *= S;
            opts[i].push_back({loss, mem});
        }
    }

    int W = T;
    vector<double> dp(W+1,INF);
    dp[0] = 0.0;

    /*
    for (int i = 1;i<=L;i++){
        vector<double>ndp(W+1,INF);
        for (int j = 0; j <= W;j++){
            if(dp[j]==INF) continue;
            for (auto &opt : opts[i]) {
                int loss = opt.first;
                double mem = opt.second;
                int new_j = j + loss;
                if (new_j <= W) {
                    ndp[new_j] = min(ndp[new_j], dp[j] + mem);
                }
            }
        }
        dp.swap(ndp);   // 进入下一层
    }
    */
    

        /*
            for(auto opt:opts[1]){
                double loss = opt.first;
                double mem = opt.second;
                dp[loss] = mem;
            }
        */

            for (int i = 1; i <= L;i++){//对于每一层

                vector<double> ndp(W + 1, INF);
                //ndp[0.0] = 0;
                for (int j = 0; j <= W;j++){//对于每一个可能的value
                    if(dp[j]==INF) continue; //仅仅讨论存在解的部分
                    for(auto node1:opts[i]){//取出在本层中每一个的情况
                        int loss = node1.first;
                        double mem = node1.second;
                        int nj = j + loss;
                        if(nj<=W){
                            ndp[nj] = min(ndp[nj], mem + dp[j]);

                        }
                    }
                }
                dp.swap(ndp);
            }

        

        double ans = INF;
    for (int i = 1; i <= W;i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
//现在主要的问题就是在之后会多次的调用j=0，但是这个是为了第一次的情况进行处理的
*/