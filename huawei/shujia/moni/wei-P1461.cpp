#include<bits/stdc++.h>
using namespace std;

int dis(int a,int b){
    int s = a ^ b;
    int cnt;
    while(s){
        if((s&1)==1)
            cnt++;
        s>>1;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,b,d;
    cin >> n >> b >> d;

    int INF = (1 << b);
    vector<int> arr;
    arr.push_back(0);
    for (int i = 1; i <= INF;i++){
        int flag = 1;
        for(auto a:arr){
            if(dis(a,i)<d){
                flag = 0;
                break;
            }
        }
        if(flag)
            arr.push_back(i);
    }
    int cnt=0;
    for (int i = 0; i < arr.size();i++){
        cout << arr[i] << ' ';
        cnt++;
        if(cnt==10){
            cout << endl;
        }
    }
    return 0;

}
// 没有想到竟然全部都是使用暴力过的
