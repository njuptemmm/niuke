#include<bits/stdc++.h>
using namespace std;
int main(){
    int h, w, k1, k2;
    cin >> h >> w >> k1 >> k2;
    vector<vector<int>> arr(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> ce(k1 + 1, vector<int>(k2 + 1, 0));
    vector<vector<double>> energy(h + 1, vector<int>(w + 1, 0));
    

    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= k1;i++){
        for (int j = 1; j <= k2;j++){
            cin >> ce[k1][k2];
        }
    }
    
    vector<int> rx={-1,0,1,-1,1,-1,0,1};
    vector<int> ry={-1,-1,-1,0,0,1,1,1};
    
    



}
/*
- 难度不是很大的dp。需要限时全力完成




*/