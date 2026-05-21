#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    // 创建一个 (n+1) x (n+1) 的 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    // 初始化 dp[0][0] = 1
    dp[0][0] = 1;

    // 动态规划求解
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            //j是总数，i是表示从1~i；
            dp[i][j] = dp[i - 1][j]; // 不使用当前数 i
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i][j - i]) % MOD; // 使用当前数 i
            }
        }
    }
    

    // 输出结果
    cout << dp[n][n] << endl;
    
    return 0;
}
// 在这种dp的题目中，最重要的是关于dp的状态定义
/*
* dp[i][j]=>总数是j，对于前i个数字来说
* dp[i][j] 表示从 1 到 i 的数中，划分出和为 j 的不同方式数目，且满足划分中的每个数都不小于上一个数。
* 如果我们不使用数 i，那么答案就和 dp[i-1][j] 相同；如果我们使用数 i，那么我们需要在 dp[i][j-i] 的基础上加上一个 i
* 主要就是在讨论到当前的节点i的时候，分为两种情况：
    - 当我们使用的时候处理使用i和不使用的两种情况

*/
