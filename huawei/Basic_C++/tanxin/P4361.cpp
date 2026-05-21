#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<int> visited(n + 1, -1);
        for (int i = 1; i <= n;i++){
            cin >> arr[i];
        }
        auto cmp = [](const auto &a, const auto &b)
        {
            return a > b;
        };
        sort(arr.begin()+1,arr.end(),cmp);

        bool flag = true;
        for (int i = 1; i <= n;i++){
            if(arr[i]==0){
                flag = false;
                break;
            }
            int num = arr[i];
            while(num>0){
                if(num>=1&&num<=n&&visited[num]==-1){
                    visited[num] = 1;
                    break;
                }
                else if(num==1){//直到这个时刻还没有匹配成功就说明是真的没有办法进行匹配了；
                    flag = false;
                }
                num /= 2;
            }
            if(!flag)//在当前这个数字中出现问题之后后面就不用进行讨论了
                break;
        }
        if(flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
/*
- 其实我对于本题的贪心思路来说其实没有特别好的方法，隐约想到可以使用从大往小来进行处理看
*/