#include<bits/stdc++.h>
using namespace std;

long long ans=0;

void dfs(vector<vector<int>>& adjList,vector<long long>& arr,int node,int parent){
    if(adjList[node].size()==1&&node!=1){
        return;
    }
    long long v_child = 0;
    for(auto num:adjList[node]){
        if(num!=parent){
            dfs(adjList,arr,num,node);
            v_child+=arr[num];
        }
    }
    if(arr[node]<v_child){
        ans += v_child - arr[node];
        arr[node] = v_child;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long long> arr(n + 1, 0);
    vector<vector<int>> adjList(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];//即是数据库的权值
    }
    for (int i = 0; i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(adjList, arr, 1, -1);
    cout << ans << endl;
    return 0;
}
/*
一道相当有意思的题目
- 主要就是对于叶子节点的判断。原来我是想着使用双向图的时候仅有一条双向边就能说明其为叶子节点
- 但是后面在计算的时候发现有一种特殊情况需要进行处理：即当根节点仅有一个子节点的时候，此时正好符合条件但是肯定不是中止的条件
*/