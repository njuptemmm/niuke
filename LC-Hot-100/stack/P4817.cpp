#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    vector<int> pre(n);//搜集最小值
    pre[0] = INF;
    int min_val = INF;
    for (int i = 1; i < n;i++){
        min_val = min(min_val, arr[i-1]);
        pre[i] = min_val;
    }

    stack<int>s;//存储单调递减的单调栈
    vector<int> ans(n);//存储相关的解（index）

    for (int i = 0; i < n;i++){
        if(i==0){
            s.push(i);
            ans[i] = -1;
        }
        else{
            while(!s.empty()){
                int j=s.top();
                s.pop();
                if(arr[j]>arr[i]){
                    s.push(j);
                    s.push(i);
                    ans[i] = j;
                    break;
                }
            }
            if(s.empty()){
                ans[i] = -1;
                s.push(i);
            }
        }
    }
    // 使用ans可以得出距离当前index最近，比当前index大的值。
    bool flag = false;
    for (int k = 2; k < n;k++){
        int j = ans[k];
        if(j==-1) continue;
        int min = pre[j];//
        if(min<arr[k]){
            flag = true;
        }
    }
    if(flag)
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*
- 一开始接触本题的时候对于解决的方法仅有简单的看法，但是一直没有整理出正确的思路

- 关键的思路在于：对于我们的k，我们要找到离k最近的j，满足arr[j]>arr[k];使用单调栈存储index很容易得出
    - 此外通过是以哦那个前缀和维护的最小值来实现知道之前的值是怎样的

*/
