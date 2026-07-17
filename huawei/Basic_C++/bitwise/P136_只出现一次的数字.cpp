/*
 * P136 - 只出现一次的数字
 *
 * 题目描述：
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
 * 找出那个只出现了一次的元素。
 *
 * 示例 1：
 * 输入：[2, 2, 1]
 * 输出：1
 *
 * 示例 2：
 * 输入：[4, 1, 2, 1, 2]
 * 输出：4
 *
 * 提示：
 * 使用线性时间复杂度，且不使用额外空间。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或的性质：
        // 1. a ^ a = 0
        // 2. a ^ 0 = a
        // 3. a ^ b ^ a = b ^ (a ^ a) = b ^ 0 = b
        // 所以把所有数异或在一起，出现两次的都会抵消，剩下的就是只出现一次的

        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}
