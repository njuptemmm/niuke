#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    unordered_set<string> arr;
    string str = "";
    for (int i = 0; i < s.length();i++)
    {
        if(s[i]=='d'){
            if(str!="")
                arr.insert(str);
            str = "";
            i++;
        }
        else{
            str += s[i];
        }
    }
    cout<<arr.size()<<endl;
    return 0;
}