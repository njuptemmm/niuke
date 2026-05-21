#include<bits/stdc++.h>
using namespace std;

int ans=0;

void dfs(vector<vector<int>>& adjList,int n,int end){
    if(n==end){
        ans++;
        return;
    }
    for(auto num:adjList[n]){
        dfs(adjList, num, end);
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    while(m--){
        int u, v;
        cin>>u>>v;
        if(u!=v){
            adjList[u].push_back(v);
            //这里的图是单向的图，仅仅存在u->v这样的路线
        }
    }
    int s, t;
    cin >> s >> t;
    dfs(adjList, s, t);
    cout << ans << endl;
    return 0;
}