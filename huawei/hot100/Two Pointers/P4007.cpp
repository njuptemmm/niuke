#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);

    unordered_set<char> st;

    int ans=-1;
    int j = 0;
    int n=s.size();
    for (int i = 0; i < n;i++){
        //f(j)
        while(j<=n-1&&!st.count(s[j])){
            st.insert(s[j]);
            j++;
            if(j==n) break;
        }
        //其实建议将count中访问的j改成j+1；
        //直接使用j的时候是已经到了重复的那位数字了，使用j+1说明是在那位数字的前一位
        ans = max(ans,j-i);
        st.erase(s[i]);
    }

    cout << ans << endl;
    return 0;
}
//使用hash的形式来保证不会出现重复的问题