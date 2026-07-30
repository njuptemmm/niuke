#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> st;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
        st.insert(arr[i]);//相关的值最后是乱序存储在里面
    }

    int max_len = -1;

    for(int i:st){
        if(st.count(i-1)) continue;
        else{
            int len = 1;
            while(1){
                i++;
                if(st.count(i)){
                    len++;
                }
                else
                    break;
            }
            max_len = max(max_len, len);
        }
        
    }

    cout << max_len << endl;
    return 0;
}
// 使用hash，所以说我们所有的数据都是乱序地存储在这个set中
// 如何我们使用vector来存储其中数据会因为数值过大而出现爆空间
// 在理解上面两个前提之后才能理解本题的深意