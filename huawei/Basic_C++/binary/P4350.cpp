#include<bits/stdc++.h>
using namespace std;

int value(int n){
    return (1 + n) * n / 2;
}

bool check(long long x, long long n, long long m, long long k) {
    if (x == 0) return true;
    long long needed = x; // 小明自己需要 x 个

    // 计算左边小孩需要的苹果数
    long long left_kids = k - 1;
    if (left_kids > 0) {
        // 苹果数从 x-1 递减到 1 的小孩数量
        long long l = min(left_kids, x - 1);
        // 等差数列求和 (x-1 + x-l) * l / 2，简化为 l*x - l*(l+1)/2
        needed += l * x - l * (l + 1) / 2;
        // 剩下的小孩每人一个
        if (left_kids > l) {
            needed += (left_kids - l);
        }
    }

    // 计算右边小孩需要的苹果数
    long long right_kids = n - k;
    if (right_kids > 0) {
        // 苹果数从 x-1 递减到 1 的小孩数量
        long long r = min(right_kids, x - 1);
        // 等差数列求和
        needed += r * x - r * (r + 1) / 2;
        // 剩下的小孩每人一个
        if (right_kids > r) {
            needed += (right_kids - r);
        }
    }
    
    return needed <= m;
}

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    long long left = 1;
    long long right = m;
    long long ans = 0;
    while(right>=left){
        long long mid = (left + right) / 2;
        bool result = check(mid, n, m, k);
        if(result){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}