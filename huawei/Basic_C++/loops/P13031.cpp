#include<iostream>
using namespace std;
const int N = 1010;
int main(){
    int n, m;
    int a_sum=0 ,b_sum=0;
    cin >> n >> m;
    int a[N];
    int b[N];
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        a_sum += num;
    }
    for (int i = 0; i < m;i++){
        int num;
        cin >> num;
        b_sum += num;
    }
    if(a_sum == b_sum)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    return 0;
}