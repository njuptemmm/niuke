#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string line;
    vector<int> arr; 
    while(getline(cin,line)){
        stringstream ss(line);
        int num;
        while(ss>>num){
            arr.push_back(num);
        }
    }
    int n = arr.size();
    
   /*
   int n;
    cin >> n;
    vector<int> arr(n); 
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
   */
    

    // 对于左右两个方向求解最小栈
    stack<int> left_s;
    stack<int> right_s;
    vector<int> min_l(n);
    vector<int> min_r(n);

    /*
    for (int i = 0; i < n;i++){
        if(i==0){
            min_l[i] = -1;
            left_s.push(i);
            continue;
        }
        while(!left_s.empty()){
            int j = left_s.top();
            left_s.pop();
            if(arr[i]>arr[j]){
                left_s.push(j);
                left_s.push(i);
                min_l[i]=j;
                break;
            }
        }
        if(left_s.empty()){
            min_l[i] = -1;
            left_s.push(i);
        }
    }
    */
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();//直接找出所需的解
        min_l[i] = st.empty() ? -1 : st.top();// 在这里使用empty判断来实现值得处理
        st.push(i);
    }
    

    for (int i = n-1; i >=0;i--){
        if(i==n-1){
            min_r[i] = -1;
            right_s.push(i);
            continue;
        }
        while(!right_s.empty()){
            int j = right_s.top();
            right_s.pop();
            if(arr[i]>arr[j]){
                right_s.push(j);
                right_s.push(i);
                min_r[i]=j;
                break;
            }
        }
        if(right_s.empty()){
            min_r[i] = -1;
            right_s.push(i);
        }
    }

    int max_val = -1;
    for (int i = 0; i < n; i++){
        int left  = (min_l[i] == -1) ? 0       : min_l[i] + 1;
        int right = (min_r[i] == -1) ? n - 1   : min_r[i] - 1;
        int len = right - left + 1;
        max_val = max(max_val, len * arr[i]);
    }
    cout << max_val << endl;
    return 0;
}
/*
- 回忆note中没有直接给你数据让你进行处理的处理方法

- 使用两段单调栈是正确的，这样对于arr[i]来说，这个值左右两边的单调栈其实就是解
    - 这个值是确定了当前arr[i]左右的的值，从而可以求解出对应的矩形


- 需要对于单调栈进行总结，看看能不能写得简洁一些。

// min_l[i]: 左侧最近且严格更小的下标，没有则 -1
stack<int> st;
vector<int> min_l(n);
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    min_l[i] = st.empty() ? -1 : st.top();
    st.push(i);
}


*/