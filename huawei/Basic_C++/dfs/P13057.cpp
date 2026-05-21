#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;

void dfs(vector<int>*tree,vector<int>&path,int n,int parent){
    path.push_back(n);
    for(auto& num:tree[n]){
        if(num!=parent){
            dfs(tree, path, num, n);
        }
    }
}

int main(){
    int n;
    int type;
    cin >> n >> type;
    vector<int> tree[MAX];
    vector<int> path;

    if(type==1){
        int num;
        string line;
        //输入相关数据
        while(getline(cin, line)){
            stringstream ss(line);
            int a, b;
            ss >> a >> b;   
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
    else{
        //使用type2是表示节点的父节点
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> parent;
        int num;
        while(ss>>num){
            parent.push_back(num);
        }
        for (int i = 0;i<parent.size();i++){
            tree[i].push_back(parent[i]);
            tree[parent[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n;i++){
        sort(tree[i].begin(), tree[i].end());
    }
    dfs(tree,path,1,0);

    for (int i = 0; i < path.size();i++){
        if(i>0)
            cout << ' ';
        cout << path[i];
    }
    return 0;
}