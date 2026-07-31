#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    unordered_set<int> row;
    unordered_set<int> col;

    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==0){
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (int i = 0; i < m;i++){
        if(row.count(i)){
            for (int j = 0; j < n;j++){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        for (int j = 0; j < n;j++){
            if(col.count(j))
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//要使用原地算法可以直接将数组挪到arr[1][1]?