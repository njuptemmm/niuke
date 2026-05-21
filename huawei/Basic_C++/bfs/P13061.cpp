#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> maze(n,vector<int>(m,0));
    //相关的地图是存储在maze中间，也就是可以使用01来判断当前节点是不是一个合法节点
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> maze[i][j];
        }
    }
    int sx, sy, zx, zy;
    cin>>sx>>sy>>zx>>zy;
    if(sx<0||sx>=n||sy<0||sy>=m||zx<0||zx>=n||zy<0||zy>=m){
        cout<<"NO"<<endl;
        return 0;
    }
    queue<pair<int,int>> path;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    //用来表示移动
    vector<int>dx ={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

    path.push({sx,sy});
    bool flag=false;
    while(path.size()!=0){
        auto present = path.front();//取出要讨论的节点
        path.pop();
        int nowX = present.first;
        int nowY = present.second;

        if(nowX==zx&&nowY==zy){
            flag=true;
            break;
        }

        for (int i = 0; i < 4;i++){
            int newX=nowX+dx[i];
            int newY = nowY + dy[i];

            if(newX>=0&&newX<n&&newY>=0&&newY<m&&!visit[newX][newY]&&maze[newX][newY]==0){//在当前的图里面的时候
                path.push({newX,newY});
                visit[newX][newY] = true;
            }
        }
        
    }
    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
/*
- 关键是队列path中是要存储对应的pair<int,int>的信息，也就是要将一个个节点作为队列的条件
*/