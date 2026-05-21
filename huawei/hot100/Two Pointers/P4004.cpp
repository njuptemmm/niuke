#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int right = n;
    int max_left = -1;
    int max_right=-1;
    int ans=-1;
    for (int left = 0; left < n;left++){
        if(arr[left]<=max_left) continue;
        max_left = arr[left];

        right = n;
        while(right>left){
            right--;
            if(arr[right]<max_right){
                continue;
            }
            max_right = arr[right];
            int length = right - left;
            int h = min(arr[right],arr[left]);
            ans = max(ans, length * h);
        }
    }
    cout << ans << endl;
    return 0;
}