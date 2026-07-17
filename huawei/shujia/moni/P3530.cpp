#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==2)
            cout << "-1" << endl;
        else{
            int a1 = (n - 1) / 2;
            int a2 = (n + 1) / 2;
            cout << a1 << " " << a2 << endl;
        }
    }

    return 0;
}