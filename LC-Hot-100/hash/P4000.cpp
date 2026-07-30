#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, target;
    cin >> n >> target;
    vector<int>arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n;i++){
        cin>>arr[i];
        mp[arr[i]] = i;
    }
    for (int i = 0; i < n;i++){
        int v=target-arr[i];
        if(mp.count(v)){
            int ans=mp[v];
            if(ans!=i){
                cout << i << " " << ans << endl;
                break;
            }
        }
    }
    return 0;
}