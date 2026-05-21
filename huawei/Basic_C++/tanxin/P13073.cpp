#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int>coins(n+1);
    for(int i=1;i<=n;i++){
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    sort(coins.begin() + 1, coins.end());
    int sum = 0;
    for (int i = n; i >= 1;i--){
        while(amount>=coins[i]){
            amount-=coins[i];
            sum++;
        }
    }
    if(amount==0){
        cout << sum << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}