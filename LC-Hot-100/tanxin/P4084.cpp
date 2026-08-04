#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> count(n,0);
    int right = 0;//用来不断维护在当前能够到达的最右情况
    int end = 0;//
    int ans = 0;
    for (int i = 0; i < n-1;i++){
        right = max(right, i + arr[i]);

        if(i==end){
            ans++;
            end = right;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
- 我的思路是维护一个count，在其中不断更新次数
- 主要就是在每次跳跃之后经过的数字怎么更新这个问题

- 实际的解决方法维护双指针，一个表示当前能够到达的最右情况，一个表示当前需要遍历到的底线

- 同时我们遍历只要到边界n-1 就是可行的了。

*/