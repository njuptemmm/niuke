#include<bits/stdc++.h>
using namespace std;

int n;

void dfs(int index, vector<int>& arr,vector<int>& vis,vector<int>& curr,vector<vector<int>>& res){
    if(index==n){
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < n;i++){
        if(!vis[i]){
            vis[i]=1;
            curr.push_back(arr[i]);
            dfs(index+1,arr,vis,curr,res);
            curr.pop_back();
            vis[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    */
    
    
    
    string line;
    vector<int> arr;
    while(getline(cin,line)){
        stringstream ss(line);
        int num;
        while(ss>>num){
            arr.push_back(num);
        }
    }
    n = arr.size();

    //int n = arr.size();
   

    vector<int> vis(n,0);
    vector<int> curr;
    vector<vector<int>> res;

    dfs(0,arr,vis,curr,res);

    for (auto nums:res){
        for(auto num:nums){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}