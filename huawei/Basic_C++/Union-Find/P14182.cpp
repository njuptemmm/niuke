#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

//find通过不断递归的思路回到最初的情况
int find(int x){
    if(parent[x]!=x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int xroot=find(x);
    int yroot=find(y);
    if(xroot!=yroot){
        parent[xroot] = yroot;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,
        m;
    cin >> n >> m;
    parent.reserve(n + 1);
    //init
    for (int i = 1; i <= n;i++){
        parent[i] = i;
    }
    while(m--){
        int z,x,y;
        cin >> z >> x >> y;
        if(z==1){//合并集合
            merge(x, y);
        }
        if(z==2){
            int xroot=find(x);
            int yroot = find(y);
            if(xroot==yroot){
                cout<<"Y"<<'\n';
            }
            else{
                cout << "N" << '\n';
            }
        }
    }
    return 0;
}
/*
- 管理元素所属集合的数据结构
- 将两个不同的集合合并成一个集合/查询某个元素属于哪个集合
- 我们是可以通过图论的角度来分析并查集以及并查集的作用；
- 主要的实现思路还是要看后面的实现结果
*/