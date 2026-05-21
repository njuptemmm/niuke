#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        arr[i] = num;
    }
    int target;
    cin >> target;
    int left = 1;
    int right = n;
    bool flag = false;
    while(right>left){
        int pre = arr[left] + arr[right];
        if(pre>target){
            right--;
        }
        if(pre<target){
            left++;
        }
        if(pre==target){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << left << " " << right << endl;
    }
    else{
        cout << -1 << endl;
    }

}