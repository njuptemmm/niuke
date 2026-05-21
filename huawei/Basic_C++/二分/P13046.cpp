#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    long long ans=0;
    int C;
    cin >> C;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;i++){
        int num = arr[i] + C;
        auto first = lower_bound(arr.begin(), arr.end(), num);
        auto last = upper_bound(arr.begin(), arr.end(), num);
        long long distance = last - first;
        ans += distance;
    }
    cout << ans << endl;
}