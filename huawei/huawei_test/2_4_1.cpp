//用来验证直接截断的方法是不是可行的

#include<bits/stdc++.h>
using namespace std;

double r(double d){
    const int S = 100;
    int n = (int)(S * d);
    double ans = (double)n;
    if(n+0.5>d*S)
        return ans/S;
    else if(n+0.5<d)
        return (ans+1) / S;
    else{
        if(n%2==0)
            return ans / S;
        else
            return (ans + 1) / S;
    }
}

int main(){
    double b;
    cin >> b;
    cout << r(b) << endl;
    return 0;
}
