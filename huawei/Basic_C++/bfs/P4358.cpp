#include<bits/stdc++.h>
using namespace std;

int n, m, k;

void bfs(vector<int>& choices,vector<int>& value){
    queue<int> q;
    //初始化
    for (int i = 0; i < choices.size();i++){
        q.push(choices[i]);
        value[choices[i]] = 1;
    }

    while(q.size()!=0){
        int node = q.front();
        q.pop();
        //node+choices[i]就是当前节点能够达到的情况
        for (int i = 0; i < choices.size();i++){
            int num=node+choices[i];
            num %= n;//由于题意中是可以出现
            if (num > 0&&num<=n&&value[num]==-1){
                value[num] = value[node] + 1;
                q.push(num);
            }
        }
    }
    return;
}

int main(){
    
    cin >> n >> k >> m;
    vector<int> choices;
    vector<int> value(n + 1, -1);
    for (int i = 0; i < k;i++){
        int num;
        cin >> num;
        choices.push_back(num);
    }
    bfs(choices,value);
    value[0] = 0;

    for (int i = 0; i < m;i++){
        int num;
        cin >> num;
        cout << value[num] << endl;
    }
        
    
    return 0;
}
/*
- 主要的问题是题目理解的时候出现问题所以导致计算的结果是有问题的
- 然后就是题目的一个理解问题了，主要就是这个翻转实现想了很久发现可以使用求模直接实现
*/