#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adjList,vector<bool>& visited,int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(q.size()!=0){
        int node = q.front();
        q.pop();
        visited[node]=true;
        for(int neighbor:adjList[node]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        if(u!=v){
            adjList[u-1].push_back(v-1);
            adjList[v-1].push_back(u-1);
        }
    }
    vector<bool> visited(n, false);;
    int ans = 0;
    for (int i = 0; i < n;i++){
        if(!visited[i]){
            ans++;
            visited[i] = true;
            bfs(adjList, visited, i);
        }
    }
    cout << ans << endl;
}
/*
- 只有在dfs中我们才会利用到递归的方法进行深度搜索；
- 对于bfs我们是没有递归的方法的我们是在对于每一个起点的情况下，使用了队列而已
- 总结起来就是bfs相对于dfs来说是没有递归的操作，不用使用什么parent避免出现环路这样的操心事
*/