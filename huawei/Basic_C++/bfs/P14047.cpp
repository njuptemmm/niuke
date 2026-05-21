#include<bits/stdc++.h>
using namespace std;

int n, k;

bool bfs(vector<vector<int>>& map,int f){
    //f的含义是防护服的防护等级
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> value(n,vector<int>(n,-1));//用来记录所有的点位的所需的time
    queue<pair<int, int>> q;
    q.push({0,0});

    while(q.size()!=0){
        auto node = q.front();
        q.pop();
        int now_x=node.first;
        int now_y = node.second;
        for (int i = 0; i < 4;i++){
            int new_x=now_x+dx[i];
            int new_y = now_y + dy[i];
            if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&value[new_x][new_y]==-1&&map[new_x][new_y]<=f){
                q.push({new_x, new_y});
                value[new_x][new_y] = value[now_x][now_y] + 1;
            }
        }
    }
    if(value[n-1][n-1]==-1||value[n-1][n-1]>k){
        return false;
    }
    else
        return true;
}

int main(){
    cin >> n >> k;
    vector<vector<int>> map(n, vector<int>(n, 0));
    int max_num = -1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            int num;
            cin >> num;
            map[i][j]=num;
            max_num = max(max_num, num);
        }
    }
    int left = max(map[0][0], map[n - 1][n - 1]);
    int right = max_num;
    int ans = 0;
    while(right>=left){
        int mid = (left + right) / 2;
        if(bfs(map,mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
- 题意解析：地图，找出从左上到右下路径中其中值最小的一条路
- 但是路径长度被限制为K
**思路分析**
- 首先就是这个防护能力是越大越好的-》使用二分的方法来逼近答案
- 题目转化成在当前的防护服的情况下能不能在K步通过迷宫


- sum up
    - 见到这种有着多种限制条件的问题，第一反应是确认其中是不是有部分需要使用二分法来确定其中一个限制条件
    - 将选择一个满足条件A和条件B的策略->当条件B的情况是B’的时候，此时能不能满足条件A？就可以按照这个的基础完成对于数据的处理
*/