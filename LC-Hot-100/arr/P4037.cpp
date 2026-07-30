#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        int j = (i + k) % n;
        a[j] = arr[i];
    }
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}