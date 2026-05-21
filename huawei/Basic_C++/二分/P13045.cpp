#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, Q;
    cin >> n >> Q;
    vector<int> arr;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    while(Q--){
        long long num;
        cin >> num;
        long long max_val;
        long long min_val;

        auto it1 = lower_bound(arr.begin(), arr.end(), num);
        int pos_max = it1 - arr.begin() - 1;
        if(pos_max>=0){
            max_val = arr[pos_max];
        }
        else{
            max_val = -1;
        }

        auto it2 = upper_bound(arr.begin(), arr.end(), num);
        int pos_min = it2 - arr.begin();
        if(pos_min<n)
            min_val = arr[pos_min];
        else
            min_val = -1;
            
        cout << max_val << " " << min_val << endl;
    }
    return 0;
}