#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    vector<int> dp(n+1,0);//以着i结尾的dp最大子序列
    dp[1] = arr[1];
    int max_len = arr[1];
    for (int i = 2; i <= n;i++){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        max_len = max(max_len, dp[i]);
    }
    cout << max_len << endl;
    return 0;
}
/*
- 对于这种dp的题目，最重要的是找到dp更新的规律。给出dp的公式
- 之后在这个公式的基础上完成相关的配置
*/