#include<bits/stdc++.h>
using namespace std;

int n;
void dfs(int index,vector<int>& arr,vector<string>& jian,vector<char>& curr,vector<vector<char>>& res){
    if(index==n){
        res.push_back(curr);
        return;
    }

    string str = jian[arr[index] - 2];
    for(char ch:str){
        curr.push_back(ch);
        dfs(index+1,arr,jian,curr,res);
        curr.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin>>str;
    n = str.size();
    vector<int> arr;
    for (char ch:str){
        arr.push_back(ch - '0');
    }

    vector<string> jian = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<char> curr;
    vector<vector<char>> res;

    dfs(0, arr, jian, curr, res);

    for (auto nums:res){
        for(auto num:nums){
            cout << num ;
        }
        cout << " ";
    }

    return 0;
}