#include<bits/stdc++.h>
using namespace std;

void dfs(int index,vector<int>&arr,vector<int>&curr,vector<vector<int>>& res){
    if(index==arr.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(arr[index]);
    dfs(index+1,arr, curr, res);
    curr.pop_back();
    dfs(index + 1, arr, curr, res);
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    */
    

    string line;
    vector<int> arr;
    while (getline(cin,line)){
        stringstream ss(line);
        int num;
        while(ss>>num){
            arr.push_back(num);
        }
    }
    int n = arr.size();

    vector<int> curr;
    vector<vector<int>> res;

    dfs(0, arr, curr, res);

    for(vector<int>& curr:res){
        for(int num:curr){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}