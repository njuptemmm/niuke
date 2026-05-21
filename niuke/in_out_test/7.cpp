#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long sum = 0;
        while(n--){
            int num;
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}