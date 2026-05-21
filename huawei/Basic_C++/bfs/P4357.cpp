#include<bits/stdc++.h>
using namespace std;

int n,m, k;;

int bfs(vector<vector<int>>& lines,int s,int e){
    //所有的值都认为是没有看见过的
    //vector<int> visited(n, -1);
    queue<int> q;
    vector<int> value(n, -1);
    //初始化情况
    value[s] = 0;
    q.push(s);
    for (int i = 0; i < m;i++){
        if (find(lines[i].begin(), lines[i].end(), s) != lines[i].end()) {
            for (int j = 0; j < lines[i].size();j++){
                if(lines[i][j]!=s){
                    q.push(lines[i][j]);
                    value[lines[i][j]] = 0;
                }
            }
        }
    }

    //进入bfs的循环中
    while(q.size()!=0){
        int node = q.front();
        q.pop();
        if(node==e){
            break;
        }
        for (int i = 0; i < m;i++){
            if (find(lines[i].begin(), lines[i].end(), node) != lines[i].end()) {
            //遍历当前节点的所有情况
                for (int j = 0; j < lines[i].size();j++){
                    int num = lines[i][j];//使用的是
                    if(value[num]==-1){//当前节点没有被访问的时候
                        q.push(num);
                        value[num] = value[node]+1;
                    }
                }
            }
        }
    }

    return value[e];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    //要使用什么样的数据结构来存储同一条线路相关的信息？
    vector<vector<int>> lines(m);
    for (int i = 0; i < m;i++){
        int u;
        cin >> u;
        while(u--){
            int v;
            cin >> v;
            lines[i].push_back(v);
        }
    }

    while(k--){
        int s, e;
        cin >> s >> e;
        int ans = bfs(lines, s, e);
        cout << ans << '\n';
    }
    return 0;
}
/*
- 过了几种不同的思路，感觉是只能使用暴力来求解了，看了一下题中相关数据的数据量，发现数据量不是很大？
- 意料之中的TLE了，但是不得不说，使用bfs相比于dfs有一个好处就是检错比较方便
- 分析完成之后果然就是之前发现没有太好方法的线路信息存储的部分没有处理好
    - ans中间给出了一个经过站点 x 的所有线路编号这样的思路确实是相当优秀的，确实使用这样的方法能够轻松解决
*/