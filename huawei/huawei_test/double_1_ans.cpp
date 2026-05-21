#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    int last[256];  // 记录每个字符最后出现的位置
    memset(last, -1, sizeof(last));  // 初始化为-1
    
    int l = 0;      // 窗口左边界
    int maxlen = 0; // 最大长度
    
    for (int r = 0; r < s.size(); r++) {
        char c = s[r];
        
        // 如果当前字符在当前窗口内出现过
        if (last[c] >= l) {
            l = last[c] + 1;  // 移动左边界到重复字符的下一个位置
        }
        
        // 更新当前字符的最后出现位置
        last[c] = r;
        
        // 计算当前窗口长度并更新最大值
        int len = r - l + 1;
        maxlen = max(maxlen, len);
    }
    
    cout << maxlen << endl;
    return 0;
}
