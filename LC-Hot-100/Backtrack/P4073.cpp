#include<bits/stdc++.h>
using namespace std;

int m,n;
int length;
bool flag = false;
vector<int> rx = {1, -1, 0, 0};
vector<int> ry = {0, 0, 1, -1};

void dfs(int index,string str,vector<vector<int>> mp,vector<vector<int>> vis){
    if(index==length){
        flag = true;
        return;
    }
    if(index==0){
        for (int i = 0; i <= m;i++){
            for (int j = 0; j <= n;j++){
                
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    vector<vector<int>> mp(m, vector<int>(n, 0));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> mp[i][j];
        }
    }

    string str;
    cin >> str;
    length = str.size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    

    
    return 0;
}