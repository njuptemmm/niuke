#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for
}
/*
- 存储祖先节点
    - 使用stack存储当前节点的祖先节点
        - 使用vector进行模拟
    - 使用unordered_map存储每个节点的祖先节点
    - key：stack存储的节点如何导入unordered_map中？
        - vector<unordered_map>
- f(k)
    - 这个主要是要看他们unordered_map中间数字的数量？
    - k>2之后要考虑多个node之间的祖先关系

*/