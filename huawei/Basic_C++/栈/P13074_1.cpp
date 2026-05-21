//本题中是使用到了vector模拟栈的思路完成完成，主要是因为我们要使用栈对于数据进行处理
//同时最后是要输出这个栈内部的值；
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

const int maxn = 1010;

int main(){
    string line;
    vector<int> arr;
    if(getline(cin,line)){
        stringstream ss(line);
        int num;
        while(ss>>num){
            arr.push_back(num);
        }
    }

    int top = 0;
    vector<int> stack(maxn, 0);
    for(int x:arr){
        while(1){
            bool flag=false;
            int sum=0;

            for (int i = top; i >= 0;i--){
                sum += stack[i];
                if(sum==x){
                    x += sum;
                    top = i - 1;
                    flag = true;
                    break;
                }
            }

            if(!flag)
                break;
        }

        top++;
        stack[top] = x;
    }
    while(top>0){
        cout << stack[top] << " ";
        top--;
    }

    cout << endl;

    return 0;
}