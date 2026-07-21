#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                cin >> arr[i][j];
            }
        }
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                if(i==1 && j==1){//初始值赋值
                    dp[i][j] = arr[i][j];
                }
                else if(j==1){
                    dp[i][j] = max(arr[i][j], dp[i - 1][j]);
                }
                else if(i==1){
                    dp[i][j] = dp[i][j - 1] + arr[i][j];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]+ arr[i][j]) ;
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n;i++){
            ans = max(ans, dp[i][n]);
            //ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
// 其中的难点主要就是掌握其中涉及到的dp思路
// 确定是要是要使用什么方法进行迭代的