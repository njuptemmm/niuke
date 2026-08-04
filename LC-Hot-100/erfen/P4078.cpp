#include<bits/stdc++.h>
using namespace std;

int n;

int getvalue(int i,vector<int>& arr){
    int num=arr[i];
    if(arr[i]<=arr[n-1])
        return 1;
    else
        return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    while(left<=right){
        int mid = (left + right) / 2;
        if(getvalue(mid,arr)){
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    int ans = left;

    cout << arr[ans] << endl;

    return 0;
}

/*
- 本题的算法是相当的精妙:对于这种旋转数组是使用了一个标记的操作
- 有了这个函数相当于引入参照能够进行处理.
*/