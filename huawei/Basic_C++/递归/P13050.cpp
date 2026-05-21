#include<bits/stdc++.h>
using namespace std;

int search_net(int i,int j,int n){
    if(i==0&&j==0){
        return 1;
    }
    int add = 0;
    if(j>0){
        add += search_net(i, j - 1, n);
    }
    if(i>0){
        add += search_net(i - 1, j, n);
    }
    return add;
}

int main(){
    int n;
    cin >> n;
    cout << search_net(n - 1, n - 1, n);
    return 0;
}