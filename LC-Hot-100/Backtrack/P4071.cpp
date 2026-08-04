#include<bits/stdc++.h>
using namespace std;

int t;

void dfs(int index,int sum,vector<int>& arr,vector<int>& curr, vector<vector<int>>& res){
    if(index==arr.size()){
        if(sum==t){//当我们遍历到最后一个值的时候要将这个值存储
            res.push_back(curr);
        }
        return;
    }
    if(sum>t){
        return;
    }

    int num=arr[index];
    if(sum+num>t){//在我们不取当前值的时候，也要遍历之后的部分
        dfs(index+1,sum,arr,curr,res);
        return;
    }
    else if(sum+num<t){
        //讨论在不取该值的时候
        dfs(index+1,sum,arr,curr,res);
        int count = 0;
        while(sum<=t){//遍历所有重复的情况
            sum += num;
            curr.push_back(num);
            count++;
            dfs(index+1,sum,arr,curr,res);
        }
        while(count--){
            sum -= num;
            curr.pop_back();
        }
        
    }
    else{
        sum += num;
        curr.push_back(num);
        res.push_back(curr);
        // dfs(index+1,sum,arr,curr,res);
        curr.pop_back();
        sum -= num;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n>>t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> curr;
    vector<vector<int>> res;

    dfs(0, 0, arr, curr, res);

    for(auto nums:res){
        for(int num:nums){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}