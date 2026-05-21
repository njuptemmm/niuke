#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;

    unordered_map<char, int> need;
    unordered_map<char, int> window;
    for(char ch:t){
        need[ch]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    vector<int> ans;
    while(right<s.size()){
        char ch=s[right];
        right++;

        if(need.count(ch)){
            window[ch]++;
            if(window[ch]==need[ch]){
                valid++;
            }
        }

        while(valid==need.size()){
            if(right-left==t.length()){
                ans.push_back(left);
            }

            char c=s[left];
            left++;
            if(need.count(c)){
                window[c]--;
                if(window[c]<need[c]){
                    valid--;
                }
            }
        }
    }
    for(int num:ans){
        cout << num << " ";
    }
    return 0;
}
//按照题目的思路应该长度要求一样的？