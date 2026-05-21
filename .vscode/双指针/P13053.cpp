#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;

    int left=0;
    vector<int> alphabeta(26, 0);
    int value = 0;//查看过的数值
    int min_len = str.size() + 1;
    bool flag = false;

    for (int right = 0; right < str.size();right++){
        char ch=str[right];
        if(alphabeta[ch-'a']==0){
            value++;
        }
        alphabeta[ch - 'a']++;
        if(value==26){
            flag = true;
            for (int j = left; j <= right;j++){
                char c=str[j];
                if(alphabeta[c-'a']>1){
                    alphabeta[c - 'a']--;
                }
                else if(alphabeta[c-'a']==1){
                    alphabeta[c - 'a']--;
                    left = j;
                    break;
                }
            }
            int length = right - left+1;
            min_len = min(length, min_len);
            left++;
            value--;
        }
        
    }
    if(flag)
        cout << min_len << endl;
    else
        cout << -1 << endl;
    return 0;
}