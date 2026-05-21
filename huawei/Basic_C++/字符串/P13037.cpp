#include<iostream>
#include<string>
using namespace std;

bool isHuiWen(string s){
    int l = 0;
    int r = s.length() - 1;
    while(1){
        if(l==r|l>r){
            break;
        }
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    for (int i = 0; i <=s1.length();i++){
        string s3 = s1.substr(0, i) + s2 + s1.substr(i);
        if(isHuiWen(s3)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

