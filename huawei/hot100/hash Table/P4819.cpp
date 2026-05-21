#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_set<int> s;
    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        if(s.count(num)==1){
            cout << "true" << endl;
            return 0;
        }
        else
            s.insert(num);
    }
    cout << "false" << endl;
    return 0;
}