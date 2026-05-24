#include <bits/stdc++.h>
using namespace std;

// 检查当前阈值value是否满足条件
bool check(const vector<int>& arr, long long value, long long max_cnt) {
    long long sum = 0;
    for (int num : arr) {
        sum += min((long long)num, value);
        // 提前终止，避免不必要的计算
        if (sum > max_cnt) {
            return false;
        }
    }
    return sum <= max_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读取第一行（所有数字）
    string line;
    getline(cin, line);
    stringstream ss(line);
    
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    
    // 读取最大调用量
    long long max_cnt;
    cin >> max_cnt;
    
    // 计算总调用量
    long long total = 0;
    for (int num : arr) {
        total += num;
    }
    
    // 如果总调用量不超过最大调用量，返回-1
    if (total <= max_cnt) {
        cout << "-1" << endl;
        return 0;
    }
    
    // 二分查找最大阈值
    long long left = 0;
    long long right = *max_element(arr.begin(), arr.end()); // 最大可能的阈值
    
    long long ans = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (check(arr, mid, max_cnt)) {
            // 当前阈值可行，尝试更大的阈值
            ans = mid;
            left = mid + 1;
        } else {
            // 当前阈值不可行，尝试更小的阈值
            right = mid - 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
