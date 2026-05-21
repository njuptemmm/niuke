#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = "";
    for (int i = s.length() - 1; i >= 0;i--){
        s2 = s2 + s[i];
    }

    cout << s2 << endl;
    return 0;
}