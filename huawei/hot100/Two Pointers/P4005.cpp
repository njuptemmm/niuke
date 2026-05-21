#include<bits/stdc++.h>
using namespace std;

struct node{
    int n1,n2,n3;
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin()+1,arr.end());
    vector<node> ans;

    for(int i=1;i<=n-2;i++){
        if(arr[i]>0) break;//此时和一定是大于0的
        if(arr[i]==arr[i-1]) continue;
        int left=i+1;
        int right=n;
        while(right>left){
            if(arr[right]+arr[left]+arr[i]==0){
                ans.push_back({arr[i],arr[left],arr[right]});
                while (left < right && arr[left] == arr[left+1]) ++left;
                while (left < right && arr[right] == arr[right-1]) --right;
                left++;
                right--;
            }
            else if(arr[right]+arr[left]+arr[i]<0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    if(ans.size()==0) cout<<"";
    else{
    //    cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].n1<<" "<<ans[i].n2<<" "<<ans[i].n3<<endl;
        }
    }
    return 0;
}
/*
- 判断的结果是爆内存了？
- 这题的主要问题是：我们没有保证ans的唯一性
*/