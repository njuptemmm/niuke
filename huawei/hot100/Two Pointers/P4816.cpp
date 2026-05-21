#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>a(n+1);
    vector<pair<int, int>>b(m + 1);
    vector < pair<int, int>> ans;
    for (int i = 1; i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i].first >> b[i].second;
    }

    int i = 1;
    int j = 1;
    while(i<=n&&j<=m){
        int al=a[i].first;
        int ar=a[i].second;
        int bl = b[j].first;
        int br = b[j].second;

        int left = max(al, bl);
        int right = min(ar, br);
        if(ar>br)
            j++;
        else
            i++;
        
        if(right>=left){
            ans.push_back({left, right});
        }
        
    }

    if(ans.size()==0) cout<<'0';
    else{
        cout << ans.size()<<'\n';
        for(auto a:ans){
            cout << a.first << ' ' << a.second << '\n';
        }
    }
    return 0;
}