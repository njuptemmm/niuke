#include <bits/stdc++.h>
using namespace std;

// 使用引用传递 vector<vector<int>> 和 vector<int>
void dfs(int n, const vector<vector<int>>& adjList, vector<int>& seen) {
    seen[n] = 1;
    for (auto num : adjList[n]) {
        if (!seen[num]) { // 如果这个节点还没有被访问过
            dfs(num, adjList, seen);
        }
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 使用 vector 的 vector 代替 C 风格数组
    // 这样它就是一个标准的 C++ 对象，可以方便地按引用传递
    vector<vector<int>> adjList(n + 1);
    vector<int> seen(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 != n2) {
            adjList[n1].push_back(n2);
            adjList[n2].push_back(n1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i, adjList, seen);
            ans++; // 连通分量计数
        }
    }

    cout << ans << endl;
    return 0;
}