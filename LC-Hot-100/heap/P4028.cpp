#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int> arr;
    unordered_map<int, int> mp;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        mp[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for(auto op:mp){
        int num = op.first;
        int freq = op.second;

        min_heap.push({freq,num });
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }

    for (int i = 0; i < k;i++){
        auto op=min_heap.top();
        min_heap.pop();
        cout << op.second << " ";
    }
    return 0;
}
/*
- 小根堆的使用方法？

- 在heap中导入类型参数的方法

- 使用请decltype(cmp) 导入我们创建的新的cmp
*/