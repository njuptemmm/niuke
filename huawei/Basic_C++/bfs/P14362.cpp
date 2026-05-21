#include<bits/stdc++.h>
using namespace std;

int m, n;

void bfs(vector<vector<int>>&map,vector<vector<int>>&dis,queue<pair<int,int>>& q){

    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    while(q.size()!=0){
        auto node = q.front();
        q.pop();
        int nowX = node.first;
        int nowY = node.second;
        for (int i = 0; i < 4;i++){
            int newX=nowX+dx[i];
            int newY=nowY+dy[i];
            if(newX>=0&&newX<m&&newY>=0&&newY<n&&dis[newX][newY]==-1&&map[newX][newY]!=-1){
                //为什么上面的遍历是可以的呢？我们最开始存入的节点都是dis值为0 的节点，所以说见到一个还没有访问过的点就知道当前的路径一定是最小的路径。
                dis[newX][newY] = dis[nowX][nowY] + 1;
                q.push({newX, newY});
            }
            
        }
    }
}
int solve(vector<vector<int>>&map,vector<vector<int>>&dis){
    int ans = 0;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if(map[i][j]==1){
                if(dis[i][j]==-1)
                    continue;
                ans += dis[i][j];
            }
        }
    }
    return ans;
}

int main(){
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n, 0));
//    vector<pair<int, int>> g_nodes;//用来存储所有垃圾桶的位置
    vector<vector<int>> dis(m, vector<int>(n, -1));
    queue<pair<int,int>> q;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            int num;
            cin >> num;
            map[i][j] = num;
            if(num==0){
//                g_nodes.push_back({i, j});
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    bfs(map,dis,q);

    cout << solve(map, dis) << endl;
    return 0;
}
/*
- 我们往常的题目是单源bfs，也就是说一张图的可达与不可达是看起点能不能与终点通过各种方式进行连接的。
- 这里我们是由多个终点，计算不同起点到最近终点的距离
    - 这个时候我们就有一个比较优秀的思路：将所有终点共同维护一张map，以每个终点向外扩散，这样再这张路径地图中，我们可以从路径地图中访问对应的点来确定最终的值是怎么样的
*/