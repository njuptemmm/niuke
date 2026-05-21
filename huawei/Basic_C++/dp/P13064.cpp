#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n+1);
    a[1] = 1;
    a[2] = 2;
    for(int i=3;i<=n;i++){
        a[i] = a[i-1]+a[i-2];
    }
    cout << a[n] << endl;
    return 0;
}