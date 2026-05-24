#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,Q;
    cin >> n >> Q;
    vector<int> arr;
    for (int i = 1; i <= n;i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    while(Q--){
        int num;
        cin >> num;

        //left和right都是索引
        int left = 0;
        int right = n-1;
        bool flag = false;
        while(left<=right){
            int mid = (right + left) / 2;
            if(arr[mid]==num){
                flag = true;
                break;
            }
            if(arr[mid]>num){
                right = mid-1;
            }
            if(arr[mid]<num){
                left = mid+1;
            }

        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}