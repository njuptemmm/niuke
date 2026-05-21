#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> sub(n + 1,0);
    int sum = 0;
    int min_val = 0;//在i之前的数据中最小的前缀和；
    int ans = -INF;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        sub[i] = sub[i - 1] + arr[i];
        int current = sub[i] - min_val;
        ans = max(ans, current);
        min_val = min(sub[i], min_val);//截止到i的时候的时候
    }

    cout << ans << endl;
    return 0;
}