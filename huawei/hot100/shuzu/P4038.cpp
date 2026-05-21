#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    vector<int> sub(n+1);
    vector<int> after(n+1);

    int s = 1;
    for (int i = 1; i <= n;i++){
        sub[i] = s;
        s *= arr[i];
    }

    int l = 1;
    for (int i = n; i >= 1;i--){
        after[i] = l;
        l *= arr[i];
    }

    for (int i = 1; i <= n;i++){
        int ans = sub[i] * after[i];
        cout << ans << " ";
    }
    cout << '\n';
    return 0;
}