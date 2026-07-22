#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long NEG = -(1LL << 60); // 负无穷替代

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 迭代 DFS：求父亲与后序顺序
        vector<int> par(n + 1, 0), order;
        order.reserve(n);
        stack<int> st;
        st.push(1); par[1] = -1;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : g[u]) if (v != par[u]) {
                par[v] = u; st.push(v);
            }
        }
        reverse(order.begin(), order.end()); // 后序

        // 每个结点一份 dp 数组
        vector<vector<long long>> dp(n + 1);
        auto merge = [&](const vector<long long>& A, const vector<long long>& B) {
            int la = (int)A.size(), lb = (int)B.size();
            vector<long long> C(la + lb - 1, NEG);
            for (int i = 0; i < la; ++i) if (A[i] > NEG / 2) {
                for (int j = 0; j < lb; ++j) if (B[j] > NEG / 2) {
                    C[i + j] = max(C[i + j], A[i] + B[j]);
                }
            }
            return C;
        };

        for (int u : order) {
            vector<long long> cur(1, 0); // 只选 0 个
            for (int v : g[u]) if (par[v] == u) {
                cur = merge(cur, dp[v]);
            }
            if ((int)cur.size() < 2) cur.resize(2, NEG);
            cur[1] = max(cur[1], a[u]); // 选 u
            dp[u].swap(cur);
        }

        // 输出 f(1..n)
        for (int k = 1; k <= n; ++k) {
            long long val = (k < (int)dp[1].size() ? dp[1][k] : NEG);
            if (k > 1) cout << ' ';
            if (val <= NEG / 2) cout << -1;
            else cout << val;
        }
        cout << "\n";
    }
    return 0;
}
