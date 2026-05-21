#include<iostream>
using namespace std;

int main(){
    long long num,sum = 0;
    while(cin>>num){
        sum += num;
    }
    cout << sum << endl;
    return 0;   
}