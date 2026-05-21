#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    unordered_map<int,int> mp;
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
        mp.insert({arr[i],-1});
    }
    
    //我觉得是可以使用一个map来存储相关的信息-》value的时候存储的是以这个为开头的时候所能达到的最长的长度；
    //之后再遇到讨论过的key的时候，可以直接调用对应的值实现计算

    int max_len = -1;

    for(auto const& p:mp){
        int key = p.first;//key是我们当前讨论到的值；
        int len = 1;

        int node = key + 1;//用来标注接下来节点的key的值
        while(mp.count(node)){//不进行优化看看能不能实现了；
            if(mp[node]!=-1){
                len=len+mp[node];
                break;
            }
            len++;
            node++;
        }

        max_len = max(max_len, len);
    }

    cout << max_len << endl;
    return 0;
}
/*
- 在这一题中是因为不能重复所以说使用这样的方法？
*/
