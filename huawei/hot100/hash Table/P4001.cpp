#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    
    //使用hash table的方法将不同的str进行分类
    unordered_map<string, vector<int>> mp;
    for (int i = 1; i <= n;i++){
        string str=arr[i];
        sort(str.begin(),str.end());
        mp[str].push_back(i);
    }
    
    for (const auto& node :mp){
        for(auto num:node.second){
            cout << arr[num] << " ";
        }
        cout << '\n';
    }
    return 0;
}