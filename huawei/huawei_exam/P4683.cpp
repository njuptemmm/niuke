#include<bits/stdc++.h>
using namespace std;


void quickSort(vector<int> &arr,int left,int right){
    if(left>=right)
        return;
    int p=arr[left];
    int i = left + 1;
    for (int j = left + 1; j <= right;j++){
        if(arr[j]<=p){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i-1], arr[left]);
    quickSort(arr,left,i-2);
    quickSort(arr, i, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    quickSort(arr, 1, n);
    for (int i = 1; i <= n;i++){
        cout << arr[i] << ' ' ;
    }
    return 0;
}