#include<bits/stdc++.h>
using namespace std;
int n, amount;

const int INF = 1e6 + 7;

int main(){
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < n;i++){
        cin >> coins[i];
    }
    cin >> amount;
    if(amount==0)
        cout << -1 << endl;
    vector<int> dp(amount + 1, INF);
    //先对于dp进行初始化？
    for (int i = 0; i < n;i++){
        int node = coins[i];
        dp[node]=1;
    }
    for (int i = 1; i <=amount;i++){
        for(auto coin:coins){
            if(i-coin>0&&dp[i-coin]!=INF){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    int ans = dp[amount] == INF ? -1 : dp[amount];
    cout << ans << endl;
    return 0;
}

/*
- 状态转移的思路是：dp[i]=min(dp[i],dp[i-coins[j]]+1);
*/