//https://codefun2000.com/p/P4547
//这题是理解出现了问题：其实我们只要处理最长子段
#include<bits/stdc++.h>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int maxlen = -1;
    int l = 0;
    int r = 0;
    unordered_map<char, int> arr;
    for(char ch:s){
        auto a = arr.find(ch);
        
        //当ch在之前出现的时候：
        if(a!=arr.end()&&arr[ch]>=l){
            l=arr[ch]+1;
        }
        arr[ch] = r;
        int len = r - l + 1;
        maxlen = max(maxlen, len);
        r++;
    }
    cout << maxlen<< endl;
    return 0;
}