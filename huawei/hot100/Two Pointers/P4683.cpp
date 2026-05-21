#include<bits/stdc++.h>
using namespace std;

void quicksort(int l,int r,vector<int>& arr){
    if(l>=r){
        return;
    }

    int x=arr[r];
    int i = l;
    for (int j = l; j < r;j++){
        if(arr[j]<=x){
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[i],arr[r]);

    quicksort(l,i-1,arr);
    quicksort(i+1,r,arr);

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n;i++){
        cin>>arr[i];
    }

    quicksort(1,n,arr);

    for (int i = 1; i <= n;i++){
        cout<<arr[i]<<" ";  
    }

    return 0;

}