#include<bits/stdc++.h>
using namespace std;

int N;

void dfs(vector<vector<int>> &adjList,vector<int>& visit,vector<int>& path,int n,int sum){
    //如果已经有n个数据进入，说明此时已经完成了一条完整道路的选择
    if(sum==N){
        for (int i = 0; i < N;i++){
            cout << path[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (auto num:adjList[n]){   
        if(visit[num]==0){
            visit[num] = 1;
            path.push_back(num);
            sum++;
            dfs(adjList, visit, path, num, sum);
            sum--;
            path.pop_back();
            visit[num] = 0;
        }
    }
}

int main()
{
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //现在主要的问题是：我们使用这样的邻接表的前提是，我们所有的数据都是在N这个范围里面的，然后就可以保证
    //我们仅要使用一个
    vector<vector<int>> adjList(N+1);
    vector<int> visit(N);
    vector<int> path;

    /*
    //构建一个全连接的连接器
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            if(i!=j)
                adjList[arr[i]].push_back(arr[j]);
        }
    }
    //遍历所有开始的情况：
    */
    
    for (int i = 0; i < N;i++){
        dfs(adjList, visit, path, arr[i], 0);
    }
        
    return 0;
}

/*
总体的思路是没有问题的，但是现在主要的问题是：
- 没有想到其实这个问题由于是使用所有的路线，所以说我们是没有必要一个个搭建双向图的
- 在判断是否完成的时候可以使用数组大小与path大小进行分析
*/