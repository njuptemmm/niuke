#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    unordered_map<char, int> mp;
    //cin >> s;
    int left = 0;
    int max_len = -1;
    for (int right = 0; right < s.size();right++){
        char ch = s[right];
        //auto result = mp.find(ch);
        if(mp.find(ch)!=mp.end()){
            left = max(left, mp[ch] + 1);
        }
        mp[ch] = right;
        int len = right - left + 1;
        max_len = max(max_len, len);
    }
    cout << max_len << endl;
    return 0;
}
// 关于其s的输入。使用cin是可以自动处理出现的空格
// 使用getline可以实现输入的时候保留相关空格
