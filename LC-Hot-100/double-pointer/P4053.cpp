#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    unordered_map<char, int> need;
    for(char ch:t){
        need[ch]++;
    }

    unordered_map<char, int> window;
    int left = 0;
    int count = 0;
    int start = -1;
    int min_len = INF;
    for (int right = 0; right < s.size();right++){

        char ch=s[right];
        if(need.count(ch)){
            window[ch]++;
            if(need[ch]==window[ch]){
                count++;
            }
        }

        while(count==need.size()){
            int len = right - left + 1;
            if(len<min_len){
                start = left;
                min_len = len;
            }

            char c=s[left];
            left++;
            if(need.count(c)){
                if(window[c]==need[c]){
                    count--;
                }
                window[c]--;
            }
        }
    }
    if(start==-1)
        cout << "";
    else{
        for (int i = start; i < start + min_len;i++){
            cout << s[i];
        }
    }
    
    
    return 0;
}