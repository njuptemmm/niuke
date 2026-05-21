#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        // 点赞数 -> 对应的杂乱度集合
        unordered_map<long long, vector<long long>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].push_back(c[i]);
        }

        // 每个点赞数列表排序（从小到大方便 pop 最大值）
        for (auto &kv : mp) {
            sort(kv.second.begin(), kv.second.end());
        }

        // 所有点赞数按升序排序
        vector<long long> keys;
        keys.reserve(mp.size());
        for (auto &kv : mp) keys.push_back(kv.first);
        sort(keys.begin(), keys.end());

        long long ans = 0;

        // 从后往前贪心成组
        while (!keys.empty()) {
            while (!keys.empty() && mp.find(keys.back()) == mp.end()) {
                keys.pop_back(); // 跳过已空的点赞组
            }
            if (keys.empty()) break;

            long long curMax = 0;
            // 从连续点赞数的末尾往前取
            for (int i = (int)keys.size() - 1; i >= 0; i--) {
                // 如果断开（不连续 或 没有该点赞值的剩余 Plog）
                if (i != (int)keys.size() - 1 && keys[i] != keys[i + 1] - 1) break;
                if (mp.find(keys[i]) == mp.end()) break;

                // 取该点赞组最大杂乱度
                auto &v = mp[keys[i]];
                curMax = max(curMax, v.back());
                v.pop_back();
                if (v.empty()) mp.erase(keys[i]);
            }
            ans += curMax;
        }

        cout << ans << "\n";
    }
    return 0;
}

/*
- Plog有a和c两个属性
- 分成n的收藏夹
- 要求是的所有的收藏夹杂乱度之和最小
- 主要的限制条件是在同一个收藏夹中间，我们的点赞数是要符合顺序的序列的
- 个人的思路是统计点赞数量的分布，然后根据这个分布的信息来进行分析处理
- 思路就是直接对于每一个的点赞数量进行处理；
- 在我们实际运行的时候发现：map的key值是过多导致后面讨论分析挺困难，给出的解决思路使用一个新的数组来存储这个信息；
*/