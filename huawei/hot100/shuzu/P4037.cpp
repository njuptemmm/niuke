#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cin >> k;
    k %= n;
    reverse(arr.begin()+1,arr.end());
    reverse(arr.begin()+1,arr.begin()+k+1);
    reverse(arr.begin()+k+1,arr.end());
    for(int i=1; i<=n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}
//主要就是了解这个函数reverse；