#include<bits/stdc++.h>
using namespace std;

int check(int a,int b,int c,int x,int y,int v){
    if(a<v)
        return 0;
    int a_b = (a - v) / x;
    if(b+a_b<v)
        return 0;
    int b_c = (b + a_b - v) / y;
    if(c+b_c<v)
        return 0;
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        int left = min(a, min(b, c));
        int right = a + b + c;
        int mid;
        int ans=0;
        while(right>=left){
            mid = (left + right) / 2;
            int result = check(a, b, c, x, y, mid);
            if(result){
                left = mid+1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}