#include<bits/stdc++.h>
using namespace std;

void dfs(const vector<int>& arr, int start, int target, 
         vector<int>& path, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(path);
        return;
    }
    
    for (int i = start; i < (int)arr.size(); ++i) {
        // 关键的去重逻辑：在同一层递归中跳过相同的元素
        if (i > start && arr[i] == arr[i - 1]) {
            continue;
        }
        
        // 剪枝：如果当前元素已经大于目标值，后面的元素更大，直接返回
        if (arr[i] > target) {
            break;
        }
        
        path.push_back(arr[i]);
        dfs(arr, i + 1, target - arr[i], path, ans);
        path.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
    }
    sort(arr.begin(), arr.end());
    //使用哈希表对u与原来的数据进行去重
    /*
    vector<int> arr1;
    unordered_map<int, int> hash;
    for(int num:arr){
        if(hash.find(num)==hash.end()){
            hash[num]++;
            arr1.push_back(num);
        }
    }
    */
    int target;
    cin >> target;
    vector<vector<int>> ans;
    vector<int> path;
    dfs(arr,0,target,path,ans);
    if(ans.empty()){
        cout << endl;
        return 0;
    }
    //对于ans中间的数据需要去重

    for(vector<int> combination:ans){
        sort(combination.begin(), combination.end());
        for(int num:combination){
            cout << num << " ";
        }
        cout << "\n";
    }
}