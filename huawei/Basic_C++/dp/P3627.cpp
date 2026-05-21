#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= n;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=i){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
                //保证这个i仅仅使用一次
                
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
/*
- 从分析的思路来说，其实我觉得这个的解法和前面的01背包是相似的
- **完全背包和01背包的总结**
- 主要的差距是在dp算法后面的部分
    - 01背包：后面部分我们使用的是dp[i][j-i];
        - 其中前面部分是i说明就是我们可以重复使用第i个数字，使用j-i就可以综合相关的信息
    - 完全背包：后面部分我们使用的dp[i-1][j-i];
        - 我们是找到除了这个i以外的数据，于是我们使用的是i-1；然后总数再转化成j-i来实现


*/