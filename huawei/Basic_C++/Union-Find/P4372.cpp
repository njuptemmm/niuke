#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

//用来寻找编号对应的父节点
int search(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        parent[x] = search(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int xroot=search(x);
    int yroot=search(y);
    if(xroot!=yroot){
        parent[xroot] = yroot;//合并到同一个数据中
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>a(n+1);
        vector<int>b(n+1);

        //讨论并查集的数据范围是m
        parent.resize(m + 1);
        vector<int> visited(m+1,-1);
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n;i++){
            cin >> b[i];
        }
        for(int i=1;i<=m;i++){
            parent[i] = i;
        }

        //创建连通块
        int sum = 0;
        for (int i = 1; i <= n;i++){
            int n1=a[i];
            int n2=b[i];
            if(visited[n1]==-1){
                visited[n1]=1;
                sum++;
            }
            if(visited[n2]==-1){
                visited[n2]=1;
                sum++;
            }
            merge(n1, n2);
        }

        //清点连通块的数量:使用vector存储就可以了
        /*vector<int> result;//用来记录已经访问过的roots
        for (int i = 1; i <= m;i++){
            if(visited[i]==1){
                int root=search(i);
                if (find(result.begin(), result.end(), root) == result.end()) {
                    result.push_back(root);
                }
            }
        }*/

        int c = 0;
        for (int i = 1; i <= m;i++){
            if(parent[i]==i&&visited[i]==1)
                c++;
        }

        int ans = sum - c;
        cout << ans << '\n';
    }
    return 0;
}
/*
- 其实就是一个绘制连通块的问题
    - 将ai和bi之间绘制一个无向边；
    - 然后你就会发现对于每一个连通块中，这一个连通块中所有的值都会归一到同一个值中间
    - 对于连通块数量的问题那就直接使用并查集就可以了

    - 根据上面的分析我们可以得出一个等式：ans=sum-c(并查集的数量)

- 反思：
    - 感觉在使用result存储数据的那一块中，判断的效率有点低；
        - 当我们使用并查集寻找root的时候最方便的方式是对于parent数组进行遍历，因为root节点始终满足parent[i]=i;
*/