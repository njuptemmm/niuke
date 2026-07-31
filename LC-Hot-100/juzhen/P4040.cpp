#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    int left = 0;
    int right = n - 1;
    while(right>left){
        int len = right - left;
        for (int i = 0; i <len;i++){
            int a = arr[left][left+i];
            arr[left][left+i] = arr[right-i][left];
            arr[right-i][left]=arr[right][right-i];
            arr[right][right-i] = arr[left+i][right];
            arr[left+i][right] = a;
        }
        right--;
        left++;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout<< arr[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}