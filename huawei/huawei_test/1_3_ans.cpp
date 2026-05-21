#include <bits/stdC++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    if (!getline(cin, text)) return 0;
    string line;

    // 读取 n
    getline(cin, line);
    int n = stoi(line);

    // 词表
    unordered_map<string, int> score;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        // 简单分割（替换字符+输入流）
        stringstream ss(line);
        string w; int p;
        ss >> w >> p;
        score[w] = p;
        maxLen = max(maxLen, (int)w.size());
    }

    // 读取 m
    getline(cin, line);
    int m = stoi(line);

    // 转移加分表
    unordered_map<string, unordered_map<string, int>> bonus;
    for (int i = 0; i < m; i++) {
        getline(cin, line);
        stringstream ss(line);
        string u, v; int x;
        ss >> u >> v >> x;
        bonus[u][v] = x;
    }

    int L = (int)text.size();
    // dp[i]: map<最后一个词, 最优总分>
    vector<unordered_map<string, int>> dp(L + 1);

    for (int i = 1; i <= L; i++) {
        int up = min(maxLen, i);
        for (int len = 1; len <= up; len++) {
            string w = text.substr(i - len, len);
            auto itw = score.find(w);
            if (itw == score.end()) continue;
            int base = itw->second;
            int j = i - len;
            if (j == 0) {
                auto it = dp[i].find(w);
                if (it == dp[i].end()) dp[i][w] = base;
                else it->second = max(it->second, base);
            } else {
                if (dp[j].empty()) continue;
                for (auto &pr : dp[j]) {
                    const string &u = pr.first;
                    int val = pr.second;
                    int add = 0;
                    auto itu = bonus.find(u);
                    if (itu != bonus.end()) {
                        auto itv = itu->second.find(w);
                        if (itv != itu->second.end()) add = itv->second;
                    }
                    int cand = val + base + add;
                    auto it = dp[i].find(w);
                    if (it == dp[i].end()) dp[i][w] = cand;
                    else it->second = max(it->second, cand);
                }
            }
        }
    }

    if (dp[L].empty()) {
        cout << 0 << "\n";
    } else {
        int ans = INT_MIN / 4;
        for (auto &pr : dp[L]) ans = max(ans, pr.second);
        cout << ans << "\n";
    }
    return 0;
}
