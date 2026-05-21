#include<bits/stdc++.h>
using namespace std;

int n, amount;

void bfs(vector<int>& coins,vector<int>& value){
    queue<int> q;
    for (int i = 0; i < coins.size();i++){
        int node=coins[i];
        value[node]=1;
        q.push(node);
    }
    
    while(q.size()!=0){
        int node=q.front();
        q.pop();
        for (int i = 0; i < coins.size();i++){
            int num = node + coins[i];
            if(num<=amount&&value[num]==-1){
                value[num] = value[node] + 1;
                q.push(num);
            }
        }
    }
    return;
}

int main(){
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < n;i++){
        cin >> coins[i];
    }
    cin >> amount;
    if(amount==0)
        cout << -1 << endl;
    //先来尝试使用bfs来解决
    vector<int> value(amount + 1, -1);

    bfs(coins, value);

    cout << value[amount] << endl;
    return 0;
}
/*
- 话说为什么我觉得可以使用bfs来解决也这个问题？
- 在之后使用dp的方法重新对于这一题进行求解
*/