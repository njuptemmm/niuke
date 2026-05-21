#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;//first是重量，second是价值
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a.second*1.0/a.first > b.second*1.0/b.first;
    });
    double ans=0;
    for(int i=0;i<n;i++){
        if(c>=arr[i].first){
            ans+=arr[i].second;
            c-=arr[i].first;
        }else{
            ans+=(double)arr[i].second/arr[i].first*c;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;   
}
/*
- 主要的问题是在使用的时候发现初始的0造成的影响
 */