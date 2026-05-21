#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<long long> prices(n + 1);
    //vector<int> package(m + 1);
    vector<int> ddl(n + 1,0);//用来储存最晚发货日要发包裹的数量
    for (int i = 1; i <= n;i++){
        cin >> prices[i];
    }
    for (int j = 1; j <= m;j++){
        int date;
        cin >> date;
        ddl[date]++;
    }
    auto cmp = [](const auto &a, const auto &b)
    {
        return a.first > b.first;
    };

    priority_queue<pair<long long, int>,vector<pair<long long,int>>,decltype(cmp)>
        minHeap(cmp); // 默认情况下这个是一个maxHeap，需要转换成minHeap

    long long ans = 0;
    // 对于相关订单进行维护
    for (int i = 1; i <= n;i++){
        long long p = prices[i];//当天发货的价格
        minHeap.push({p,x});//第一个存入的是price，第二个是amount
        int num = ddl[i];
        if(num==0) continue;
        //对于当天的情况进行分析
        while(1){
            auto node = minHeap.top();
            minHeap.pop();
            if(num>node.second){
                num -= node.second;
                ans += node.second * node.first;//此时我们使用的金钱
            }
            else{
                node.second -= num;
                ans += node.first * num;//这里我们实际使用的num的部分
                minHeap.push(node);//将本次使用中没有使用完成的数据返回minHeap中
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
- 在贪心的时候遇到了这种有多种条件限制的问题，解决的方法是？
    - 我个人觉得似乎应该从限制条件最大的固定限制开始进行考虑；
- 现在关键的问题是在于：
    - 维护一个随着遍历变化的数列，能够一直更新当前最优的选择-》这里我们是使用hea来解决
**本题的解答思路**
1. 将原来的m个订单-》在每一天中有多少的订单最晚发货日期是当天（这个能想到）
2. 进行贪心选择。维护一个pq，保存所有的发货机会的heap，下面是维护方法
    - 到了第i天的时候将第i天的发货机会传入这个heap中
    - 在heap中取出响应数量的发货机会发货，这样我们就可以保证能够充分利用所有的发货机会

- 这一题的真正收获其实还真就是在对于Lambda的了解以及整理heap的使用方法()


*/