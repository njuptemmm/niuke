/*
 * P191 - 位1的个数
 *
 * 题目描述：
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位为 '1' 的个数。
 *
 * 示例 1：
 * 输入：n = 00000000000000000000000000001011
 * 输出：3
 * 解释：输入的二进制串中，共有 3 个 '1'。
 *
 * 示例 2：
 * 输入：n = 00000000000000000000000010000000
 * 输出：1
 * 解释：输入的二进制串中，共有 1 个 '1'。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 方法1：Brian Kernighan 算法
        int cnt = 0;
        while (n) {
            n &= n - 1;  // 消除最低位的 1
            cnt++;
        }
        return cnt;

        // 方法2：逐位检查
        // int cnt = 0;
        // for (int i = 0; i < 32; i++) {
        //     if (n & (1 << i)) cnt++;
        // }
        // return cnt;

        // 方法3：lowbit
        // int cnt = 0;
        // while (n) {
        //     n -= n & -n;  // 减去最低位的 1
        //     cnt++;
        // }
        // return cnt;
    }
};

int main() {
    uint32_t n;
    cin >> n;

    Solution sol;
    cout << sol.hammingWeight(n) << endl;

    return 0;
}
