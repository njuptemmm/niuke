#include<bits/stdc++.h>
using namespace std;

long long value(long long n){
    return (n + 1) * n / 2;
}

int main(){
    int n;
    cin >> n;
    unordered_map<char,int> left;//用来存储左边出现的数字和出现的次数
    int ans = 0;
    long long bao = 0;

    string s;
    cin >> s;

    for (int i = 0; i < n;i++){
        char ch = s[i];
        left[ch]++;
        long long sum = value(i+1);
        long long b = value(left[ch])-value(left[ch]-1);
        bao += b;
        long long count = sum - bao;
        cout << count << endl;
    }
    
    return 0;
}