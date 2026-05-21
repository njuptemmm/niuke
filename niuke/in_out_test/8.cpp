#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j<m;j++){
            int num;
            cin >> num;
            sum += num;
        }
    }
    cout << sum << endl;
    return 0;
}