#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        int start = l / n;
        int end = r / n+1;
        int min_val=INF;
        int max_val = -INF;
        for (int i = start; i <= end;i++){
            if(n*i>=l&&n*i<=r){
                min_val = min(min_val, i);
                max_val = max(max_val, i);
            }
        }
        if(min_val==INF){
            cout << -1<<'\n';
        }
        else{
            cout << min_val << " " << max_val << endl;
        }
    }
    return 0;
}