/*
 * P231 - 2的幂
 *
 * 题目描述：
 * 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true；否则，返回 false。
 *
 * 示例 1：
 * 输入：n = 1
 * 输出：true
 * 解释：2^0 = 1
 *
 * 示例 2：
 * 输入：n = 16
 * 输出：true
 * 解释：2^4 = 16
 *
 * 示例 3：
 * 输入：n = 3
 * 输出：false
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 关键观察：2的幂的二进制表示中只有一个1
        // 例如：1(1), 2(10), 4(100), 8(1000), 16(10000)

        // 方法1：使用 n & (n - 1) 消去最低位的1
        // 如果消去后变成0，说明原来只有一个1
        return n > 0 && !(n & (n - 1));

        // 方法2：使用 lowbit
        // return n > 0 && (n & -n) == n;

        // 方法3：循环除以2
        // if (n <= 0) return false;
        // while (n % 2 == 0) n /= 2;
        // return n == 1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << (sol.isPowerOfTwo(n) ? "true" : "false") << endl;

    return 0;
}
