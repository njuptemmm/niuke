#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    stack<char> s;

    for(char ch:str){
        if(ch!=']'){
            s.push(ch);
        }
        else{
            string str_w;
            while(1){
                char c = s.top();
                s.pop();
                if(c=='[') break;
                else{
                    str_w.push_back(c);
                }
            }
            reverse(str_w.begin(), str_w.end());

            string str_v;//求解出对应的值
            while(1){
                if(s.empty())
                    break;
                char c = s.top();
                s.pop();
                if(c<'0'||c>'9'){//说明此时已经是到头的了。此时就要将这个值存储。
                    s.push(c);
                    break;
                }
                else{
                    str_v.push_back(c);
                }
            }
            reverse(str_v.begin(), str_v.end());

            int num=0;
            for(char c:str_v){
                num += c - '0';
                num *= 10;
            }
            num /= 10;
            string str1 = "";
            while(num--){
                str1 += str_w;
            }

            for (char c:str1){
                s.push(c);
            }
        }
    }
    string ans="";
    while(!s.empty()){
        char c=s.top();
        s.pop();
        ans += c;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}

// 本题中使用stack似乎是用来解决嵌套问题
/*
- e.g. 4[2[a]]
- 原来的思路是将其中的所有的都存入之后再来使用颠倒
*/