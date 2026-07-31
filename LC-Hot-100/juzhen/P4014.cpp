#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    int left = 0;
    int right = n - 1;
    int head = 0;
    int bottom=m-1;
    vector<int> ans;
    while(left<=right&&head<=bottom){
        if(left==right&&head==bottom){
            ans.push_back(arr[left][head]);
            break;
        }
        for (int i = left; i < right;i++){
            ans.push_back(arr[head][i]);
        }
        for(int i=head;i<bottom;i++){
            ans.push_back(arr[i][right]);
        }
        for (int j = right; j > left;j--){
            ans.push_back(arr[bottom][j]);
        }
        for (int i = bottom; i > head;i--){
            ans.push_back(arr[i][left]);
        }
        left++;
        right--;
        head++;
        bottom--;
    }
    for(int x:ans){
        cout << x << " ";
    }
    return 0;
}
/*
- 感觉是可以使用递归的思路来求解？ 
*/