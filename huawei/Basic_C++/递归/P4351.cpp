#include<bits/stdc++.h>
using namespace std;

vector<string> MAP = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

//arr存储的是所有的数字位数；
void dfs(vector<char>arr,int i,string path,vector<string>& ans){
    //arr.size()对应数字比实际索引多一个，于是可以直接处理
    if(i==arr.size()){
        ans.push_back(path);
        return;
    }
    string &letters = MAP[arr[i] - '0'];
    for(char ch:letters){
        path.push_back(ch);
        dfs(arr, i+1, path, ans);
        path.pop_back();
    }
}

vector<string> comb(vector<char>&arr){
    vector<string> ans;
    if(arr.empty())
        return ans;
    string path;
    dfs(arr, 0, path, ans);
    return ans;
}

int main(){
    string line;
    cin >> line;
    stringstream ss(line);
    vector<char> arr;
    char num;
    while(ss>>num){
        arr.push_back(num);
    }
    //arr存储的是所有的数字位数；

    auto ans = comb(arr);
    for(string s:ans){
        cout << s << "\n";
    }
    return 0;
}