#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr;
    int num;
    
    // 读取输入
    while(cin >> num){
        arr.push_back(num);
    }
    
    stack<int> stk;
    
    // 处理每个元素
    for(int i : arr){
        stk.push(i);
        
        // 检查栈中是否有至少三个元素
        if(stk.size() >= 3){
            // 弹出三个元素检查
            int top1 = stk.top(); stk.pop();
            int top2 = stk.top(); stk.pop();
            int top3 = stk.top(); stk.pop();
            
            // 如果三个元素相同，则消除（不压回栈）
            if(top1 == top2 && top2 == top3){
                // 消除，不压回
            } else {
                // 不相同，按原顺序压回
                stk.push(top3);
                stk.push(top2);
                stk.push(top1);
            }
        }
    }
    
    // 将栈中元素转移到vector中（此时是逆序）
    vector<int> result;
    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }
    
    // 反转得到正确顺序
    reverse(result.begin(), result.end());
    
    // 输出结果
    if(result.empty()){
        cout << "[]" << endl;
    } else {
        for(int i = 0; i < result.size(); i++){
            if(i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}
