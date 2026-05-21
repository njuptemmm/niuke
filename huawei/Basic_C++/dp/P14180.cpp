#include<bits/stdc++.h>
using namespace std;

struct node{
    int l, w, h;
};

int main(){
    int n;
    cin >> n;
    vector<node> arr(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i].l >> arr[i].w >> arr[i].h;
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        if(a.l!=b.l){
            return a.l < b.l;
        }
        if(a.w!=b.w){
            return a.w < b.w;
        }
        
        return a.h < b.h;
        
    });

    vector<int> dp(n + 1);//dp[i]在放置dp[i]的时候所能达到的最高的高度
    for (int i = 1; i <= n;i++){
        int height = arr[i].h;
        for (int j = 1; j <i;j++){
            if(arr[i].l>arr[j].l&&arr[i].w>arr[j].w&&arr[i].h>arr[j].h){
                height = max(height, dp[j] + arr[i].h);
            }
        }
        dp[i] = height;
    }
    int ans=0;
    for (int i = 1; i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}