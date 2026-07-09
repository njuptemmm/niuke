//本题真正应该讨论的思路是使用堆的思路，维护一个堆，存储数值和对应的调用次数
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    vector<int> ans(n+1,0);
    //对于存入heap的node，first表示其数值，second表示其使用次数
    auto cmp = [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second > b.second;
    };
    priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (int i = 1; i < n;i++){//能够到达第n个国家，说明是我们只要讨论n-1次的移动
        if(pq.empty()||arr[i]==arr[pq.top().first]){
            pq.push({i, 1});
        }
        else{
            if(arr[i]<arr[pq.top().first]){
                while(!pq.empty()){
                    pair<int, int> t = pq.top();
                    ans[t.first] = t.second;
                    pq.pop();
                }
                pq.push({i, 1});
            }
            else{
                pair<int, int> t = pq.top();
                pq.pop();
                pq.push({t.first, t.second + 1});
            }
        }
    }
    while(!pq.empty()){
        auto t=pq.top();
        ans[t.first]=t.second;
        pq.pop();
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
//最后存储在pq的结果是一个堆
//堆的first应该是arr的序号
/*
- 本题的核心难点是：动态维护最值；我们每一次的选择都是最值，但是我们可以发现这个最值是会随着遍历改变
- 这题实际也是适合使用set来进行处理，set的begin()也是不断取出第一个
*/
