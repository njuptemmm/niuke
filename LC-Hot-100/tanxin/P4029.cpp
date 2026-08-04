#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> sub(n);
    int max_val = -INF;
    for (int i = n - 1; i >= 0;i--){
        if(i==n-1){
            sub[i] = -INF;
            max_val = max(max_val, arr[i]);
        }
        else{
            sub[i] = max_val;
            max_val = max(max_val, arr[i]);
        }
    }

    int ans = -1;
    for (int i = 0; i < n;i++){
        if(arr[i]<sub[i]){
            int val = sub[i] - arr[i];
            ans = max(ans, val);
        }
    }
    if(ans==-1)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}