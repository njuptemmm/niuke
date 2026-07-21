#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b>0){
        int u=a%b;
        a = b;
        b = u;
    }
    return a;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int ans = -1;
    for (int u = 2; u <= 100;u++){
        int cnt=0;
        for (int i = 0; i < n;i++){
            int num=arr[i];
            if(num%u==0){
                cnt++;
                i++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
    
}
