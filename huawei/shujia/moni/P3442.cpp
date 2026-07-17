#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> arr;
        arr.push_back(n);
        for (int i = 0; i < 20;i++){
            if(((n>>i)&1)==0){
                long long ans=n | (1 << i);
                arr.push_back(ans);
            }
        }
        cout << arr.size() << endl;
        for (int i = 0;i<arr.size();i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    
}

// 具体有关的位运算的知识已经整理在notebook中间了
// 主要就是位运算中相关算法处理的收集
// 其中还有一个重要的问题是：在使用位运算相关的运算过程的时候，需要使用相关的括号来确定不同部分的值
// - 即当你需要的是你位运算的结果的时候，需要使用括号将相关运算结果提取出来