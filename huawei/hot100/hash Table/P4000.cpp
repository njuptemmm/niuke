#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> arr(n + 1,-INF);
    unordered_map<int,int> mp;
    for (int i = 1;i<=n;i++){
        cin >> arr[i];
        mp.insert({arr[i], i});//key:值，value：索引；
    }
    sort(arr.begin() + 1, arr.end());
    for (int i = 1; i <= n;i++){
        if(arr[i]==arr[i-1]) continue;//避免出现重复
        int c=arr[i];//c为当前讨论的值
        int node = target - c;//node为当前输出的值
        if(c>=node) continue;
        if(mp.count(node)){
            cout << mp.at(c)-1 << ' ' << mp.at(node)-1 << endl;
        }
    }
    return 0;
}