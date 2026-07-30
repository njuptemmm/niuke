#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pre(n);
    vector<int> after(n);

    int l = 0;
    int r = 0;
    for (int i = 0; i < n;i++){
        cin>>arr[i];
        pre[i] = l;
        l = max(l, arr[i]);
        
    }
    for (int i = n - 1; i >= 0;i--){
        after[i] = r;
        r = max(r, arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n;i++){
        int num=0;
        int height = min(pre[i], after[i]);
        if(arr[i]<height){
            num = height - arr[i];
        }
        sum += num;
    }
    cout << sum << endl;
    return 0;
}