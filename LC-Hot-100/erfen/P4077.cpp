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
    int target;
    cin >> target;

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

    if(target>arr[n-1]){
        left = 0;
        right = ans - 1;
    }
    else{
        left = ans;
        right = n - 1;
    }

    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]<target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    int final=left;
    if(arr[final]==target&&final>=0&&final<n)
        cout << final<< endl;
    else
        cout << "-1" << endl;
    return 0;
}
