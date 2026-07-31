#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;

    stack<char> s;

    for(char ch:str){
        if(s.empty()){
            s.push(ch);
        }
        else{
            char c = s.top();
            s.pop();
            if((c=='('&&ch==')')||(c=='['&&ch==']')||(c=='{'&&ch=='}')){
                continue;
            }
            else{
                s.push(c);
                s.push(ch);
            }
        }
    }

    if(s.empty())
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}