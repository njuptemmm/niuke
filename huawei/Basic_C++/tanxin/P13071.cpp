#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> prices(n + 1);
    for(int i=1;i<=n;i++){
        cin >> prices[i];
    }
    for (int i = 2; i <= n;i++){
        if(prices[i]>prices[i-1]){
            ans+=prices[i]-prices[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}