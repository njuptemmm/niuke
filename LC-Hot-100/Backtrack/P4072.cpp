#include<bits/stdc++.h>
using namespace std;

int n;
void dfs(int index,int sum,vector<int>& curr,vector<vector<int>>& res){
    // 两种不同的结束方式
    if(index==2*n){
        if(sum==0){
            res.push_back(curr);
        }
        return;
    }
    if(sum<0)
        return;

    curr.push_back(1);
    sum++;
    dfs(index+1,sum,curr,res);
    curr.pop_back();
    sum--;

    curr.push_back(-1);
    sum--;
    dfs(index+1,sum,curr,res);
    curr.pop_back();
    sum++;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> curr;
    vector<vector<int>> res;

    dfs(0,0,curr,res);

    for (auto nums:res){
        for(auto num:nums){
            if(num==1)
                cout << "(";
            else 
                cout<<")";
        }
        cout << endl;
    }
    return 0;
}
/*
- 所以说我们最后的解决方法是抛开数量相等直接遍历得了
*/