#include<bits/stdc++.h>
using namespace std;

string str_reserve(string s){
    if(s.length()==1)
        return s;
    return str_reserve(s.substr(1)) + s[0];
}

int main(){
    string str;
    cin >> str;
    str=str_reserve(str);
    cout << str << endl;
    return 0;
}
