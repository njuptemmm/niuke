#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<int> rack;

int minCost(int l,int r){//用来处理l，r之间的最小代价
    if(l>r){
        return 0;
    }
    if(r==l){
        return 2;//此时我们使用的就是列的那一个情况了
    }
    //寻找当前部分的最小值
    int minH = INF;
    for (int i = l; i <= r;i++){
        minH = min(minH, rack[i]);
    }

    int cost1 = 1;
    int i = l;
    while(i<=r){
        //当前的服务器的高度高于minH的时候我们才开始对于这个进行讨论；
        if(rack[i]>minH){//这里的i是要不断更新的
            int start = i;
            while (i <= r&&rack[i]>minH){
                i++;
            }
            cost1 += minCost(start, i - 1);
        }
        else{
            i++;//否则我们就直接跳过当前服务器开始讨论
        }
    }

    return cost1;
}


int main(){
    int n;
    cin >> n;
    rack.resize(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> rack[i];
    }
    int ans = minCost(1, n);
    cout << ans << endl;
    return 0;
}
/*
- 在我们使用贪心相关的算法的时候会发现我们有很多的算法会和递归的思路结合在一起
- 对于某个小情况进行讨论和拓展
*/