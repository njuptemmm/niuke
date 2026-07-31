#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    vector<int> pre(n);
    vector<int> sub(n);

    int num = 1;
    for (int i = 0; i < n;i++){
        if(i==0) pre[i]=1;
        else{
            num *= arr[i - 1];
            pre[i] = num;
        }
    }

    num = 1;
    for (int i = n - 1; i >= 0;i--){
        if(i==n-1)
            sub[i] = 1;
        else{
            num *= arr[i + 1];
            sub[i] = num;
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n;i++){
        ans[i] = pre[i] * sub[i];
    }
    for (int i = 0; i < n;i++){
        cout << ans[i]<<" ";
    }
    return 0;
}