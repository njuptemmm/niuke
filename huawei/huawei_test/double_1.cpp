#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int count = 0;
    unordered_map<char, int> arr;
    for(char ch:s){
        auto a = arr.find(ch);
        if(a==arr.end()){
            count++;
            arr[ch] = 1;
        }
    }
    cout << count << endl;
    return 0;
}