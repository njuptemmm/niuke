#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int left=0;
    int right=n-1;
    int max_l=-1;
    int max_r = -1;
    int ans = -1;

    while(right>=left){
        //计算当前的值
        int len = right - left ;
        int val = min(arr[left], arr[right]);
        int num = len * val;
        ans=max(ans,num);
        max_l = arr[left];
        max_r = arr[right];

        if(arr[left]<arr[right]){
            while(left<n){
                left++;
                if(arr[left]>max_l)
                    break;
            }
        }
        else{
            while(right>=0){
                right--;
                if(arr[right]>max_r)
                    break;
            }
        }
    }

    cout << ans << endl;
}