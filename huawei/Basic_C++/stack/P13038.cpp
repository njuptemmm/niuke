#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    string str;
    cin >> str;
    stack<char> s;
    for(char ch1:str){
        if(s.empty()){
            s.push(ch1);
        }
       else{
            char ch2 = s.top();
            if (ch2 == '(' && ch1 == ')'){
                s.pop();
                continue;
            }
            else{
                s.push(ch1);
            }
       }
    }
    if(s.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}