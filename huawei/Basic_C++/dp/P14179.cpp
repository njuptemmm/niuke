#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    string str;
    cin >> str;
    int n = str.size();

    //dp[i][j]
    vector<vector<long long>> dp(n, vector<long long>(10, 0));
    dp[0][str[0] - '0'] = 1;//完成初始化
    for (int i = 1;i<n;i++){//对于0的部分我们都讨论完了，直接从1开始
        int node = str[i] - '0';//讨论的数字为node
        long long tot=0;

        for (int j = 0; j < 10;j++){
            if(j!=node){
                dp[i][j] = dp[i-1][j];//当不是node的时候，我更新的方式就是重复之前的值
            }
            tot = (tot + dp[i - 1][j]) % mod;//包括重复的所有的值都家就在toot里面
        }
        //处理在当前时刻存入dp的值
        dp[i][node] = (tot - dp[i - 1][node] + 1 + mod) % mod;//其中的1是仅仅使用自己这一个解
    }
    long long ans=0;
    for (int i = 0; i < 10;i++){
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout<<ans<<"\n";
    return 0;
}