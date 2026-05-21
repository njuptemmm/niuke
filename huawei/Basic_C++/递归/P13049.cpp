//整体的思路是没有问题，但是这题的要求是使用树来解决问题

#include<bits/stdc++.h>
using namespace std;

int sum_len(vector<int> arr,int n){
    int parent;
    if(n==0) return arr[0];
    else{
        
        if(n%2==0){
            parent = (n - 2) / 2;
        }
        else{
            parent = (n - 1) / 2;
        }
    }
    return sum_len(arr,parent) + arr[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    int max_len = -1;
    for (int i = 0; i < n;i++){
        max_len = max(max_len, sum_len(arr,i));
    }
    cout << max_len << endl;
    return 0;
}