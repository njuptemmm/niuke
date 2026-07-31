#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n>>k;
    priority_queue<int> hp;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        hp.push(num);
    }

    for (int i = 0; i < k;i++){
        int num=hp.top();
        hp.pop();
        if(i==k-1)
            cout << num;
    }
    return 0;
}