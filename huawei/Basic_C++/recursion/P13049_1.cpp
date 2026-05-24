#include<bits/stdc++.h>
using namespace std;

int searchTree(int i,int n,vector<int>&arr){
    int leftNode = 2 * i + 1;
    int rightNode = 2 * i + 2;
    int sum_max;

    if(leftNode>=n&&rightNode>=n){
        return arr[i];
    }
    int left_sum=-1, right_sum=-1;
    if(leftNode<n)
        left_sum = searchTree(leftNode, n, arr);
    if(rightNode<n)
        right_sum = searchTree(rightNode, n, arr);
    
    return arr[i] + max(left_sum,right_sum);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    cout << searchTree(0,n,arr) << "\n";
    return 0;
}