#include<bits/stdc++.h>
using namespace std;

bool isG(int x){
    if(x>=250&&x<=350){
        return true;
    }
    return false;
}

bool isD(int x){
    if(x>=160&&x<=250){
        return true;
    }
    return false;
}

bool isC(int x){
    if(x>=200&&x<=300){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int flag = 0;
        if(isG(n)){
            cout << "G"<<" ";
            flag++;
        }
        if(isD(n)){
            cout << "D"<<" ";
            flag++;
        }
        if(isC(n)){
            cout << "C"<<" ";
            flag++;
        }
        if(flag!=0)
            cout <<'\n';
        else 
            cout <<"other"<<"\n";
    }
    return 0;
}