#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    vector<int> max_dp(n);
    for (int i = 0; i < n;i++){
        if(i==0)
            max_dp[i] = arr[i];
        else{
            if(max_dp[i-1]>0)
                max_dp[i] += max_dp[i - 1] + arr[i];
            else{
                max_dp[i] = arr[i];
            }
        }
    }
    int max_val = -INF;
    for (int i = 0; i < n;i++){
        max_val = max(max_val, max_dp[i]);
    }
    cout << max_val;
    return 0;
}
/*
- 首先是本题数组是乱序的，所以我们没有办法使用双指针的鹅方法来进行验证（没有一个处理方向）
- 设计min_dp/max_dp：存储以该值结尾的时候的min值/max值
    - 感觉min_dp是不是比较好处理的？、
    - max_dp的求解
*/