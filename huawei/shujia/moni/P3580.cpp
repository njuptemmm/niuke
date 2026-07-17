#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        int sum=0;
        while(n--){
            int a;
            cin >> a;
            a %= 2;
            sum+=a;
            sum %= 2;
        }
        while(q--){
            int l, r, k;
            cin >> l >> r >> k;
            int length = r - l + 1;
            int add = (length + 1) / 2;
            k %= 2;
            add %= 2;
            int ans = sum + k * length + add;
            ans%= 2;
            if(ans==1)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
/*
- 主要错误的原因是：我们考虑的是整个数组的奇偶性，没有考虑替代部分的奇偶性。
- 处理方法是维护一个前序表来进行处理
*/