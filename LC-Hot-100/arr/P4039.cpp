#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_set<int> st;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
        st.insert(arr[i]);
    }
    int ans = 1;
    while(1){
        if(st.count(ans)){
            ans++;
        }
        else
            break;
    }
    cout<<ans<<endl;
    return 0;
}