#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<long long>arr(n+1);
    for (int i = 1; i <= n;i++){
        arr[i] = 1 + (i - 1) * i / 2;
    }
    for (int i = n; i >= 1;i--){
        if(m-arr[i]<=n-i){
            arr[i] = m+i-n;
        }
    }
    for (int i = 1; i <= n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}