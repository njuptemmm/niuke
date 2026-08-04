#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    */
    
    

    
     string line;
    vector<int> arr;
    while (getline(cin,line)){
        stringstream ss(line);
        int num;
        while(ss>>num){
            arr.push_back(num);
        }
    }
    int n = arr.size();


    int right = 0;
    for (int i = 0; i < n;i++){
        if(right>=i){
             right = max(right, i + arr[i]);
        }
       
    }

    if(right>=n-1)
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*
- 最开始分析的时候我认为我们应该使用的是队列的方法进行处理？但是似乎是不行的

- 后面发现其实我们不用讨论所有情况，只要不断维护一个right边界，也就是当前考虑到的边界情况
- 之后保证我们讨论的数据都是在这个right范围以内来保证正确性
*/