/*
 * P78 - 子集
 *
 * 题目描述：
 * 给你一个整数数组 nums，数组中的元素互不相同。返回该数组所有可能的子集。
 * 解集不能包含重复的子集。你可以按任意顺序返回解集。
 *
 * 示例 1：
 * 输入：nums = [1, 2, 3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 * 示例 2：
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 * 位运算思路：
 * 每个元素可以选或不选，用二进制位表示：
 * n个元素，就有 2^n 个子集
 * mask的第i位是1，表示选第i个元素
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // 枚举所有可能的 mask，从 0 到 2^n - 1
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                // 检查第 i 位是否是 1
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
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
    vector<vector<int>> ans = sol.subsets(nums);

    // 输出结果
    for (auto& subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            if (i > 0) cout << ",";
            cout << subset[i];
        }
        cout << "]" << endl;
    }

    return 0;
}
