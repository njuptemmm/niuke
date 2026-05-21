#include<bits/stdc++.h>
using namespace std;

int n;

int dfs(vector<vector<bool>>& vis,int x, int y) {
    if (x == n) return 0;  // 递归边界：到达最后一行

    // 计算下一个搜索位置
    int nextX = (y == n - 1) ? x + 1 : x;
    int nextY = (y == n - 1) ? 0 : y + 1;

    int res = 0;

    // 判断是否能放置2x2方块
    if (x + 1 < n && y + 1 < n && !vis[x][y] && !vis[x + 1][y] && !vis[x][y + 1] && !vis[x + 1][y + 1]) {
        // 标记格子为已访问
        vis[x][y] = vis[x + 1][y] = vis[x][y + 1] = vis[x + 1][y + 1] = true;

        res = max(res, dfs(vis,nextX, nextY) + 1);  // 递归继续搜索

        // 回溯，重置访问状态
        vis[x][y] = vis[x + 1][y] = vis[x][y + 1] = vis[x + 1][y + 1] = false;
    }

    // 不放置方块，继续搜索
    res = max(res, dfs(vis,nextX, nextY));

    return res;
}

int main(){
    int k;
    cin >> n >> k;
    vector<vector<bool>> vis(n,vector<bool>(n, false));
    while(k--){
        int u,v;
        cin>>u>>v;
        vis[u][v] = true;
    }
    int ans=dfs(vis, 0, 0);
    cout << ans << endl;
    return 0;
}
/*
- 其实跟之前的基于dfs找到最优path的题型是类似的。其中使用到的回溯法和本题的思路是一致的
*/