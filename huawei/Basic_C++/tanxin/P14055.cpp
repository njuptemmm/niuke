#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> value(n + 1);
    vector<vector<int>> label(m+1);//用来存储标签的信息
    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        label[num].push_back(i);
    }
    vector<int> value_1(n + 1);
    vector<int> value_2(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> value_1[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> value_2[i];
    }
    for (int i = 1; i <= n;i++){
        value[i] = value_1[i] - value_2[i];
    }
    vector<int> visited(n + 1, -1);//用来判断当前这个物品有没有被访问过

    for (int i = 1; i <= m;i++){
        if(label[i].size()==0) continue;
        sort(label[i].begin(), label[i].end(), [&value](int a, int b)//当我们在使用sort的时候需要使用其他的数组来进行排序时候似乎用的方法；
             { return value[a] > value[b]; });
        //之前我们使用的是[](auto&a,auto&b)的时候其实我们是没有指定任何数组作为排序的依据。使用这样的方法就可以实现使用特定数组进行排序
        int node = label[i][0];
        if(value[node]>0) visited[node] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n;i++){
        if(visited[i]==1){
            ans += value_1[i];
        }
        else
            ans += value_2[i];
    }
    cout << ans << endl;
    return 0;
}
/*
- 这一次问题主要是出现有一个情况没有考虑到：就是当贴标签的时候全是负面的结果的时候我们应该选择不贴标签。
*/