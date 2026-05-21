#include<bits/stdc++.h>
using namespace std;

int ans = 0;

vector<bool> dfs(vector<vector<int>>& adjList,string& s,int node,int parent){
    bool hasRed = false;
    bool hasBlack = false;
    if(s[node]=='R')
        hasRed = true;
    else hasBlack=true;
    for(auto child:adjList[node]){
        if(child==parent){
            continue;
        }
        vector<bool>ch=dfs(adjList,s,child,node);
        if(ch[0]){
            hasRed = true;
        }
        if(ch[1]){
            hasBlack = true;
        }
    }
    if(hasRed&&hasBlack){
        ans++;
    }
    return {hasRed, hasBlack};
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        if(u!=v){
            //减一之后根节点就是从0开始进行计算的
            adjList[u-1].push_back(v-1);
            adjList[v-1].push_back(u-1);
        }
    }
    dfs(adjList,s,0,-1);
    cout << ans << endl;
    return 0;
}
/*
- 关于前面比较疑问的单向边和双向边的问题，是不是和具体的题目情景是有关的？
    - 给出的parents节点的时候就是视为单向边
    - 仅仅给出边的时候就要从双向边开始考虑？
    - （经过了验证之后可以发现上面的说法是正确的）

- 此外， string s也要转化成string& s。当我们递归的长度足够长的时候会导致 Memory Exceeded
*/
