#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<long long>> dp(n, vector<long long>(10, 0));
    dp[0][s[0] - '0'] = 1;
    for (int i = 1; i < n; ++i) {
        long long tot = 0;
        int now = s[i] - '0';
        for (int j = 0; j < 10; ++j) {
            if (j != now) {
                dp[i][j] = dp[i-1][j];
            }
            tot = (tot + dp[i-1][j]) % MOD;
        }
        dp[i][now] = (tot - dp[i-1][now] + 1 + MOD) % MOD;
    }
    long long ans = 0;
    for (int j = 0; j < 10; ++j)
        ans = (ans + dp[n-1][j]) % MOD;
    cout << ans << '\n';
    return 0;
}
