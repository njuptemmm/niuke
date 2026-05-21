#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> maze(m, vector<int>(n, 0));//用来存储地图信息   
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> maze[i][j];
        }
    }

    int sx,sy,zx,zy;
    cin>>sx>>sy>>zx>>zy;
    if(sx<0||sx>=m||sy<0||sy>=n||zx<0||zx>=m||zy<0||zy>=n){
        cout<<-1<<"\n";
        return 0;
    }

    queue<pair<int,int>> path;
    path.push({sx, sy});
    vector<int> dx={1,-1,0,0};
    vector<int> dy = {0, 0, 1, -1};
    //由于我们要求解路径长度所以说我们不需要使用visit？
    //vector<vector<bool>> visit(m, vector<bool>(n, false));
    //visit[sx][sy] = true;
    vector<vector<int>> distance(m, vector<int>(n, INF));
    distance[sx][sy] = 0;

    while(path.size()!=0){
        auto present=path.front();
        path.pop();
        int nowX=present.first;
        int nowY=present.second;
        int nowD = distance[nowX][nowY];

        if(nowX==zx&&nowY==zy){
            cout <<distance[zx][zy]<< "\n";
            return 0;
        }

        for (int i = 0; i < 4;i++){
            int newX=nowX+dx[i];
            int newY=nowY+dy[i];
            int newD = nowD + 1;

            //应该有更短的距离的时候再来更新这个函数
            if(newX>=0&&newX<m&&newY>=0&&newY<n&&maze[newX][newY]==0&&newD<distance[newX][newY]){//在当前的图里面的时候
                path.push({newX,newY});
                distance[newX][newY] = newD;//仅仅只有当前的距离小于记录的距离的时候才会进行更新
            }
        }
    }
    cout << -1 << "\n";
}
/*
- 之后不能使用path来表示我们选择的路径，建议是使用q来进行表示。当我们在求解路径长度的时候，容易被这个path所误导
- 然后就是及时的出队操作。当我们访问了path里面的元素之后要即使对于其中的数据进行出队操作，不然会一直停留在path的循环中
*/