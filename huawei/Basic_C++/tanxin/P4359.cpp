#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b!=0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int left = 1;
        int ans = 0;//用来计算这种优美段的数量
        int gcd_value = -1;

        for (int right = 1; right <= n;right++){
            //当我们讨论到的节点是初始节点的时候：
            if(left==right){
                if(arr[right]==1){
                    //此时其自己一个就成为了优美段，新的优美段要重现开始进行计算{}
                    ans++;
                    left = right + 1;
                    gcd_value = -1;
                    continue;
                }
                else{
                    gcd_value = arr[right];
                }
            }
            else{
                //在当前节点求解出来的gcd
                int gcd_node=gcd(arr[right],gcd_value);
                if(right-left+1>=gcd_node){
                    ans++;
                    left = right + 1;
                    gcd_value = -1;
                    continue;
                }
                gcd_value = gcd_node;
            }
        }
        if(ans==0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
/*
- 使用gcd的时候使用辗转相除法的原因：
    - 
*/