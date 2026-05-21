#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> classes(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> classes[i].first >> classes[i].second;
    }
    sort(classes.begin() + 1, classes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // 按照结束时间排序
    });
    int ans = 0;
    int last_end_time = 0;
    for (int i = 1; i <= n;i++){
        if(classes[i].first > last_end_time){
            ans++;
            last_end_time = classes[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}