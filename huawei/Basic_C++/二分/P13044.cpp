#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, Q;
    cin >> n >> Q;
    vector<int> arr;

    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    while (Q--) {
        int x;
        cin >> x;
        
        // 使用 lower_bound 查找第一个大于等于 x 的位置
        auto first = lower_bound(arr.begin(), arr.end(), x);
        // 使用 upper_bound 查找第一个大于 x 的位置
        auto last = upper_bound(arr.begin(), arr.end(), x);
        
        // 判断元素是否存在
        if (first != arr.end() && *first == x) {
            // 元素存在，输出第一次和最后一次出现的位置
            // 注意：题目要求的位置是从1开始计数的
            cout << (first - arr.begin() + 1) << " "
                 << (last - arr.begin()) << endl;  // last指向第一个大于x的位置，所以last-1是最后一个x
        } else {
            // 元素不存在
            cout << "-1 -1" << endl;
        }
    }
    
    return 0;
}
//出现的问题是当刚刚好值是在最后一个的时候，那么会返回.end()但是此时是正确的需要进行保留
