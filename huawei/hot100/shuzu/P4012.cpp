#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n+1);
    for (int i = 1; i <= n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    auto cmp=[](const pair<int,int>& a,const pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    };

    sort(arr.begin()+1,arr.end(),cmp);
    for (int i = 1; i <= n;i++){
        int left=arr[i].first;
        int right=arr[i].second;
        int j;
        for (j = i + 1;j<=n;j++){
            if(arr[j].first>right){//说明此时就不在同一个区间了
                break;
            }
            if(arr[j].second>right){
                right=arr[j].second;
            }
        }
        cout<<left<<" "<<right<<endl;
        i=j-1;//更新i的位置
    }
    return 0;
}