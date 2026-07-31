#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    str += '/';
    stack<string> s;
    string w="";

    for(char ch:str){
        if(ch=='/'&&w==""){
            continue;
        }
        else if(ch=='/'&&w!=""){
            s.push(w);
            w = "";
        }
        else{
            w += ch;
        }
    }

    stack<string> s1;
    while(!s.empty()){
        string word = s.top();
        s.pop();
        if(word==".") continue;
        else if(word==".."){
            if(s.empty()) continue;
            s.pop();
        }
        else{
            s1.push(word);
        }
    }

    if(s1.empty()){
        cout<<"/";
        return 0;
    }

    while(!s1.empty()){
        string word = s1.top();
        s1.pop();
        cout << "/" << word;
    }


    return 0;
}
//感觉是要将其中的string 进行存储
//但是关于这个提取是有很多情况要分析