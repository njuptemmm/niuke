#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    int left = 0;
    int right = 0;
    int end = 0;
    vector<int> ans;
    unordered_map<char, int> mp;

    for (int i = 0; i < str.size();i++){
        char ch=str[i];
        mp[ch] = i;
    }
    // 需要使用什么结构来存储这个str已经访问过的结果
    for (int i = 0; i < str.size(); i++){
        char ch=str[i];
        right=max(right,mp[ch]);
        if(i==right){
            int len = right - left + 1;
            ans.push_back(len);
            left = right + 1;
        }
    }
    for(int a:ans){
        cout << a << " ";
    }

    return 0;
}
/*
- 跟上一题类似？也是要不断维护这个长度，确保没有更新
*/