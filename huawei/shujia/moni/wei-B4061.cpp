#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long  a, b;
    cin >> a >> b;
    cout << (a << b) << endl;
    cout << (a >> b) << endl;
    long long ans = (a >> b) & 1;
    long long ans1 = a &~ (1 << b);
    long long ans2 = a | (1 << b);
    long long ans3 = a ^ (1 << b);
    cout << ans << endl;
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    

    return 0;
}
// 使用位运算的方法对于值进行计算的时候，我们使用的应该都为`(1<<p)`的形式。在置0和置1的时候使用不同的运算
// 因为使用这个方法才能保证更改的仅仅是这个特定位置
