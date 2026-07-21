#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n, a, b, c;
        cin>>n>>a>>b>>c;
        vector<long long> dp(n+1, 0);
        vector<long long > endA(n+1, 0);
        dp[0]=1;
            for (int k = 1; k <= n; ++k) {
            long long v = 0;
            if (k >= a) v = (v + dp[k - a]) % MOD;
            if (k >= b) v = (v + dp[k - b]) % MOD;
            if (k >= c) {
                long long addc = (dp[k - c] - endA[k - c]) % MOD;
                if (addc < 0) addc += MOD;
                v = (v + addc) % MOD;
            }
            dp[k] = v;

            endA[k] = (k >= a ? dp[k - a] : 0);
        }

        for(int i=1;i<=n;i++){
            cout<<dp[i]<<" ";
        }

        cout<<endl;
    }
    return 0;
}