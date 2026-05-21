#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
    }
    int left = 0;
    unordered_map<int, int> hash;
    int max_len = -1;

    for (int right = 0; right < n;right++){
        int num=arr[right];
        //找到了相同的数据->对于数据进行处理
        if(hash.find(num)!=hash.end()&&hash[num]>=left){
            //主要的问题就是在这里：要确定找到的数值是在left之后我们才需要进行考虑
            left =  hash[num] + 1;
        }

        hash[num] = right;

        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << endl;
    return 0;
}