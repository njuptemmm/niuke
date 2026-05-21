#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    //我们的dp是要存储两个信息：当前的值是以什么结尾的，还有在当前结尾的值
    vector<pair<int, int>> dp;//第一个是以什么结尾，第二个是当前的值
    int ans=-1;
    for (int i = 0; i < n;i++){
        int node1 = arr[i];
        int value = 0;
        if(i==0){
            dp.push_back({node1, 1});
            continue;
        }
        for (int j = i - 1; j >= 0;j--){
            int node2 = dp[j].first;
            if(node1>node2){
                value = max(value,dp[j].second+1 );
            }
        }
        value = max(value, 1);//如果没有遇到值默认的值为1
        dp.push_back({node1, value});
        ans = max(ans, value);
    }
    cout << ans << endl;
    return 0;
}