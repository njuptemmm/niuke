#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;
    int vaild=0;
    unordered_map<char,int> need;
    for(char ch:p){
        if(!need.count(ch))
            vaild++;
        need[ch]++;
    }

    unordered_map<char, int> window;
    int left = 0;
    int count = 0;
    vector<int> ans;
    for (int right = 0; right < s.size();right++){
        char ch = s[right];
        if(need.count(ch)){
            window[ch]++;
            if(window[ch]==need[ch])
                count++;
        }

        while(vaild==count){
            if(right-left+1==p.size()){
                ans.push_back(left);
            }

            char c = s[left];
            left++;
            if(need.count(c)){
                if(window[c]==need[c]){
                    count--;
                }
                window[c]--;
                
            }
        }
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << ' ';
    }
    return 0;
}