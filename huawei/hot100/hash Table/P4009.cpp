#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    mp[0] = 1;
    long long count = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        // 先查找符合条件的前缀和数量
        int target = sum - k;
        if (mp.count(target)) {
            count += mp[target];
        }
        // 再更新当前前缀和
        mp[sum]++;
    }
    cout << count << endl;
    return 0;
}

/*
- 当我们使用前缀和的思路来解决这道问题的时候：注意到我们讨论的是当前值之前的前缀和才是满足条件的；
*/