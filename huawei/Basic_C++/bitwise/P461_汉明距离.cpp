/*
 * P461 - 汉明距离
 *
 * 题目描述：
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
 *
 * 示例 1：
 * 输入：x = 1, y = 4
 * 输出：2
 * 解释：
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 * 上面的箭头指出了对应二进制位不同的位置。
 *
 * 示例 2：
 * 输入：x = 3, y = 1
 * 输出：1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        // 步骤1：先用异或找出不同的位（不同为1）
        int diff = x ^ y;

        // 步骤2：统计 diff 中 1 的个数
        int cnt = 0;
        while (diff) {
            diff &= diff - 1;
            cnt++;
        }
        return cnt;

        // 或者一行写法：
        // return __builtin_popcount(x ^ y);
    }
};

int main() {
    int x, y;
    cin >> x >> y;

    Solution sol;
    cout << sol.hammingDistance(x, y) << endl;

    return 0;
}
