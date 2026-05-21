#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n+1);
        vector<int>c(n+1);
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n;i++){
            cin >> c[i];
        }
        unordered_map<int,vector<int>> mp;
        mp.reserve(n+1);
        for (int i = 1; i <= n;i++){
            mp[a[i]].push_back(c[i]);
        }
        for (int i = 1; i <= n;i++){
            sort(mp[i].begin(), mp[i].end());
        }
        vector<int> keys;
        for (auto kv:mp){//我们遍历键值对的时候需要使用这个方法
            keys.push_back(kv.first);
        }
        for (int i = 1; i <= keys.size();i++){
            if(!mp[keys[i]].size())
        }
    }
}