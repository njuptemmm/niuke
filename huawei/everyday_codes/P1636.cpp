#include<bits/stdc++.h>
#define int long long
using namespace std;


int change(string s){
    int ans = 0;
    for (int i = 0; i < s.length();i++){
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}


int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a,int b){
    return a / gcd(a, b) * b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--){
        string s;
        cin >> s;
        int max_lcm = -1;
        int len = s.length();
        int num1 = change(s);
        for (int i = 0; i < len;i++){
            for (int j = i + 1; j < len;j++){
                string str = s;
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
                int num2 = change(str);
                int lcm_1 = lcm(num1, num2);
                max_lcm = max(max_lcm, lcm_1);
            }
        }
        cout << max_lcm << endl;
    }
    return 0;
}