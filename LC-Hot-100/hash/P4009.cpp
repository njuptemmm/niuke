#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    vector<int> suf(n+1);
    unordered_map<int, int> mp;
    for (int i = 0; i <=n;i++){
        if(i==0) suf[i]=0;
        else{
            suf[i] = suf[i - 1] + arr[i - 1];
        }
        mp[suf[i]]++;
    }

    int ans = 0;
    for(auto op:mp){
        int val = op.first;
        if(mp.count(val+k)){
            ans += op.second * mp[val + k];
        }
    }
    cout << ans << endl;
    return 0;
}
// way1:双指针 由于值的顺序是不能变的，所以说是不能使用双指针来逃课
/*
- 错误的思路是对于其中的前缀和全部搜集完成之后再来运算。这样会导致计算前缀和的时候出现后面的前缀和影响前面的前缀和
- 于是说正确的解法是创建前缀和的时候通知进行讨论，这样一定不会讨论到后面的前缀和的部分

*/