#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;

    int left = 0;
    int right = m - 1;
    while(right>=left){
        int mid = (left + right) / 2;
        if(arr[mid][0]<=target){//当等于的时候还是在right所在的哪一行,其他情况也在right所在的那一行
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    int row=right;
    //在这里row取left获得的是大于target的情况
    //right=left-1正好就是target所在的行

    left = 0;
    right = n - 1;
    while(right>=left){
        int mid = (left + right) / 2;
        if(arr[row][mid]<target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    int col = left;

    if(row >= 0 && col < n && arr[row][col] == target) cout<<"true";
    else
        cout << "false";

    return 0;
}