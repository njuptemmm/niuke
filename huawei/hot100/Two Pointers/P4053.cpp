#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    // 统计 t 中每个字符的需求量
    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    unordered_map<char, int> window;   // 当前滑动窗口内字符计数
    int left = 0, right = 0;           // 左闭右闭窗口 [left, right]
    int valid = 0;                     // 已满足需求字符的种类数
    int start = 0, minLen = INT_MAX;   // 记录最优区间起始和长度

    while (right < s.size()) {
        char c = s[right];
        right++;                       // 右指针右移

        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        // 当前窗口已包含 t 中所有字符，尝试左移 left 缩小窗口
        while (valid == need.size()) {
            // 更新最优解
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            char d = s[left];
            left++;                    // 左指针右移

            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }

    // 输出结果
    if (minLen == INT_MAX) {
        cout << "" << endl;
    } else {
        cout << s.substr(start, minLen) << endl;
    }
    return 0;
}
