#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arra(n,0);
    vector<int> arrb(m,0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arra[i] = num;
    }
    for (int i = 0; i < m;i++){
        int num;
        cin >> num;
        arrb[i] = num;
    }
    
    int i = 0;//i:表示在a中遍历的指针
    //在子序列中，顺序是要保持不变的
    for (int j = 0; j < m; j++){
        char ch = arra[i];
        if(ch==arrb[j]){
            i++;
        }
    }
    if(i==n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}