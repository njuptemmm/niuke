#include<bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;
//int n;//其实这个感觉hyw了

//把值存储在value中，是不是就可以解决不同层dfs中数据传输的问题？
void dfs(vector<vector<int>>&adjList,vector<long long>&value,vector<int>&c,int present){
    //中止条件：
    if(adjList[present].size()==0){
        value[present] = 1;
        return ;
    }
    //获得左右孩子的序号
    int leftchild = adjList[present][0];
    int rightchild = adjList[present][1];
    if(value[leftchild]==-1){
        dfs(adjList, value, c,leftchild);
    }
    if(value[rightchild]==-1){
        dfs(adjList, value, c,rightchild);
    }
    if(c[present]==0){
        value[present] = value[leftchild] + value[rightchild];
        value[present] %= Mod;
    }
    else if(c[present]==1){
        value[present] = value[leftchild] * value[rightchild];
        value[present] %= Mod;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> parent(n+1);//第i个节点的父节点
    vector<int> c(n + 1);//第i个节点对应的运算

    for (int i = 2; i <= n;i++){
        cin >> parent[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> c[i];
    }

    //个人思路：在创建的时候是使用双向连接表，在导入dfs的时候使用的是parent+present这样的形式

    vector<vector<int>> adjList(n+1);
    vector<long long> value(n + 1, -1);

    for (int i = 2; i <= n;i++){
        int u = parent[i];//读出第i位的父节点
        if(u!=i){
            adjList[u].push_back(i);
            //adjList[i].push_back(u);
        }
    }

    dfs(adjList, value, c, 1);

    cout << value[1] << endl;
    return 0;
}
/*
- 关于二叉树的构建：是不是就是说，当我构建一个单向图，是不是就可以解决问题？
- 当前的问题是数据范围的问题：看上去我们在计算的时候爆数据范围了；
*/