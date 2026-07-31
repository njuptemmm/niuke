#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    stack<int> s;//存储的是要保存的索引
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0;i--){
        int val = arr[i];
        if(s.empty()){//初始情况
            ans[i] = 0;
            s.push(i);
            continue;
        }
        while(!s.empty()){
            int j=s.top();
            s.pop();
            if(arr[j]>val){
                s.push(j);
                s.push(i);
                ans[i] = j - i;
                break;
            }
            else continue;
        }
        if(s.empty()){//遍历stack之后发现仍为0；
            ans[i] = 0;
            s.push(i);
        }
    }
    for(int i:ans){
        cout << i << " ";
    }
    return 0;
}
/*
- 如果要使用stack应该从后往前进行处理
- 如果是要使用queue应该是从前往后处理

*/