#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int xroot = find(x);
    int yroot=find(y);
    if(xroot!=yroot){
        parent[xroot] = yroot;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> arr[i][j];
        }
    }

    //使用并查集对于我们所需的数据进行分析
    parent.reserve(n + 1);
    for (int i = 1; i <= n;i++){
        parent[i] = i;
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(arr[i][j]!=0){
                merge(i, j);
            }
        }
    }

    vector<int> mp(n + 1);//由于root一定是在n中间，于是我们不用使用hash来进行存储
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(arr[i][j]!=0){
                int root=find(i);
                mp[root] += arr[i][j];//对于map中这个数据，所有的数据都加上他们bridge的值
                arr[i][j] = 0;
                arr[j][i] = 0;
            }
        }
    }
    auto cmp=[](const auto&a,const auto&b){
        return a > b;
    };
    sort(mp.begin(),mp.end(),cmp);

    vector<int>result;
    for(int i=1;i<=n;i++){
        if(parent[i]==i){
            result.push_back(mp[i]);
        }
    }
    sort(result.begin(),result.end(),cmp);
    for(auto num:result){
        if(num>0){
            cout << num << " ";
        }
        
    }
    cout<<'\n';
    return 0;
}
/*
- 确实在没有了解并查集之前对于这种问题的没有很好的解决思路，这里我们使用其他的思路进行求解
- 题目给的例子中仅仅讨论过了进入一次时候的评价，但是没有表示形成一个回环之后的成果是怎么样的
*/