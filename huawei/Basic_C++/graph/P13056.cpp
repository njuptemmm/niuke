#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> mapa(n, vector<int>(n,0));
    vector<vector<int>> mapb(n, vector<int>(n,0));

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            int num;
            cin >> num;
            mapa[i][j] = num;
        }
    }

    for(int i = 0; i < n;i++){
        int node;
        cin >> node;
        node--;
        int k;
        cin>>k;
        for (int i = 0; i < k;i++){
            int num;
            cin >> num;
            num--;
            mapb[node][num] = 1;
            //mapb[num][node] = 1;
        }
    }

    bool flag = false;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(mapa[i][j]!=mapb[i][j]){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}