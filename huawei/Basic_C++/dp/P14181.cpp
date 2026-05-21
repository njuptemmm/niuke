#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // 前缀最大子段和
        vector<ll> pre_dp(n + 2, -INF), pre_max(n + 2, -INF);
        for (int i = 1; i <= n; ++i) {
            pre_dp[i] = max(a[i], pre_dp[i - 1] + a[i]);
            pre_max[i] = max(pre_max[i - 1], pre_dp[i]);
        }

        // 后缀最大子段和（从右向左计算）
        vector<ll> suf_dp(n + 2, -INF), suf_max(n + 2, -INF);
        for (int i = n; i >= 1; --i) {
            suf_dp[i] = max(a[i], suf_dp[i + 1] + a[i]);
            suf_max[i] = max(suf_max[i + 1], suf_dp[i]);
        }

        // 枚举第一个子段的右端点 i
        ll ans = -INF;
        for (int i = 1; i <= n - k; ++i) {
            int j = i + k + 1;  // 第二个子段的左端点
            if (j > n) break;
            ll cur = pre_max[i] + suf_max[j];
            ans = max(ans, cur);
        }

        cout << ans << endl;
    }
    return 0;
}
/*
- 在本题中主要的思维难点是在于这个前缀和后缀的处理方法。
- 我们是知道可以使用dp的思路来处理前缀和后缀中相关数值的处理，然后整体的思路就可以直接进行转化了

*/
