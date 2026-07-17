#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum<n) cout<<1<<endl;
    else{
        cout << sum - n << endl;
    }
    return 0;
}