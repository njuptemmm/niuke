#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    stack<int> data_s;
    stack<int> min_s;
    while(t--){
        string op;
        cin >> op;
        if(op=="push"){
            int val;
            cin >> val;
            if(data_s.empty()){//特判第一个的情况
                min_s.push(val);
                data_s.push(val);
                continue;
            }
            data_s.push(val);


            int min=min_s.top();
            if(val<=min)
                min_s.push(val);
        }
        if(op=="pop"){
            int val = data_s.top();
            data_s.pop();
            int min = min_s.top();
            if(val==min){
                min_s.pop();
            }
        }
        if(op=="top"){
            int val=data_s.top();
            cout << val << endl;
        }
        if(op=="getMin"){
            int min = min_s.top();
            cout << min << endl;
        }
    }
    return 0;
}
/*
sort最坏使用堆排序是o(nlogn)

- 创建两个栈分别存储最小的值？
- 但是在pop操作之后这个最小栈会出现问题
- 如何处理

- 就是直接维护最小栈！！！
    - 由于最小栈中栈的深度顺序和在数据栈的深度顺序是一样的
    - 所以说是可以直接维护最小住哪不用担心pop的时候不及时！

*/