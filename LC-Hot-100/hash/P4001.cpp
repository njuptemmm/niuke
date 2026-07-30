#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0;i < n;i++){
        cin >> arr[i];
    }

    unordered_map<string, vector<int>> mp;

    for (int i = 0; i < n;i++){
        string s=arr[i];
        sort(s.begin(), s.end());
        mp[s].push_back(i);
    }


    for(auto pair:mp){
        for(int x:pair.second){
            cout << arr[x] << " ";
        }
        cout << endl;
    }
    return 0;
}
//收集异位词的方法？
//un-map可以搜集词的信息，