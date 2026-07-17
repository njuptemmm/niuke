/*
 * P201 - 数字范围按位与
 *
 * 题目描述：
 * 给你两个整数 left 和 right，表示区间 [left, right]，
 * 返回此区间内所有数字按位与的结果（包含 left、right 端点）。
 *
 * 示例 1：
 * 输入：left = 5, right = 7
 * 输出：4
 * 解释：
 * 5 = 101
 * 6 = 110
 * 7 = 111
 * 101 & 110 & 111 = 100 = 4
 *
 * 示例 2：
 * 输入：left = 0, right = 0
 * 输出：0
 *
 * 示例 3：
 * 输入：left = 1, right = 2147483647
 * 输出：0
 *
 * 思路：
 * 只要有一位在范围内出现过0，那么这一位的与结果就是0
 * 实际上结果就是 left 和 right 的公共前缀，后面补0
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        // 找到公共前缀
        while (left < right) {
            left >>= 1;   // 右移一位
            right >>= 1;
            shift++;      // 记录移动了多少位
        }

        // 左移回去，后面补0
        return left << shift;

        // 方法2：Brian Kernighan 算法
        // while (left < right) {
        //     right &= right - 1;  // 消除 right 最低位的 1
        // }
        // return right;
    }
};

int main() {
    int left, right;
    cin >> left >> right;

    Solution sol;
    cout << sol.rangeBitwiseAnd(left, right) << endl;

    return 0;
}
