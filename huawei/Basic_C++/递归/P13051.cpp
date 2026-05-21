#include<bits/stdc++.h>
using namespace std;

int n, K;
int sx, sy, ex, ey;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int step=0;

void dfs(int i,int j,int k){
    if(i==ex&&j==ey){
        step++;
    }
    if(k==K)
        return;

    for (int dir = 0; dir < 4;dir++){
        int newX = i + dx[dir];
        int newY = j + dy[dir];
        if(newX>=1&&newX<=n&&newY>=1&&newY<=n){
            dfs(newX, newY, k + 1);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    cin >> K;

    dfs(sx,sy,0);
    cout << step << endl;
    return 0;
}
