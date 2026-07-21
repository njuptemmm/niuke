#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int m;
    cin >> m;
    vector<vector<int>> arr(2,vector<int>(m));
    for(int i=0;i<2;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int min_val=INF;
    vector<int> dp0(m, 0);
    vector<int> dp1(m, 0);
    //dp0
    for (int i = m - 1; i > 0;i--){
        if(i==m-1)
            dp0[i] = arr[0][i];
        else
            dp0[i] = dp0[i + 1] + arr[0][i];
    }
    //dp1
    for (int i = 0; i < m;i++){
        if(i==0)
            dp1[i] = arr[1][i];
        else
            dp1[i] = dp1[i - 1] + arr[1][i];
    }
    for (int flag = 0; flag < m;flag++){
        if(flag==0)
            min_val = min(min_val, dp0[flag + 1]);
        else if(flag==m-1)
            min_val = min(min_val, dp1[flag - 1]);
        else
            min_val = min(min_val, max(dp0[flag + 1], dp1[flag - 1]));
    }
    cout<<min_val<<endl;
    return 0;
}