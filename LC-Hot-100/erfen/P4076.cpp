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
    int target;
    cin >> target;

    int left = 0;
    int right = n - 1;
    int ans_l;
    int ans_r;
    //往左边进行处理
    while(right>=left){
        int mid=(right+left)/2;
        if(arr[mid]<target){
            left = mid + 1;
        }
        else{//mid为target的时候往左边跑于是为左边的value
            right = mid - 1;
        }
    }
    ans_l = left;

    left = 0;
    right = n - 1;
    //往右边进行处理
    while(right>=left){
        int mid=(right+left)/2;
        if(arr[mid]<=target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    ans_r = right;

    if(ans_r>=ans_l){
        cout << ans_l << " " << ans_r << endl;
    }
    else{
        cout << -1 << " " << -1 << endl;
    }

    return 0;
}