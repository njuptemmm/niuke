#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    int count=0;

    for (int i = 0; i < n;i++){
        int num;
        cin>>num;
        arr[i] = num;
    }
    for (int i = 0; i < n;i++){
        right[arr[i]]++;
    }
    for (int i = 0;i<n;i++){
        int num = arr[i];
        count += left[num + 1] * right[num + 1];
        left[num]++;
        right[num]--;
    }
    cout<<count<<endl;
    return 0;
}