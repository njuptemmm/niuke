#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int left = 0;
    int right = n - 1;

    //int ans;

    while(right>=left){
        int mid = (left + right) / 2;
        
        if(arr[mid]<target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        
    }
    cout << left << endl;

    return 0;
}
/*
- 
*/