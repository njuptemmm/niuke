#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);
        for (int i = 0; i < n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int node = -INF;
        for (int i = 0; i < n;i++){
            if(i==0){
                node = arr[i];
                ans.push_back(arr[i]);
                continue;
            } 
            if(abs(arr[i]-node)>d){
                ans.push_back(arr[i]);
                node = arr[i];
            }
            else{
                continue;
            }
        }
        int num=ans.size();
        if((n-num)%2==1){
            num--;
        }
        cout << num << endl;
    }
    return 0;
}