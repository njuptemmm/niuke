#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;

    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;

        if(str == "add"){
            int num;
            cin >> num;
            if (max_heap.empty() || num <= max_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }

            // 调整，使两个堆大小差不超过 1
            if ((int)max_heap.size() > (int)min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else if ((int)min_heap.size() > (int)max_heap.size() + 1) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            /*
            int min_top = min_heap.empty() ? INF : min_heap.top();
            int max_top = max_heap.empty() ? INF : max_heap.top();
            if(min_top==INF&&max_top==INF){
                max_heap.push(num);
            }
            else if(min_top==INF){
                min_heap.push(num);
            }
            else if(max_top==INF){
                max_heap.push(num);
            }
            else{
                if (num <= max_top){
                    max_heap.push(num);
                }
                else{
                    min_heap.push(num);
                }
            }
            int len = max_heap.size() - min_heap.size();
            if(len<=-2){
                int num = min_heap.top();
                min_heap.pop();
                max_heap.push(num);
            }
            if(len>=2){
                int num = max_heap.top();
                max_heap.pop();
                min_heap.push(num);
            }
            */
            
        }
        
        if(str=="median"){
            double ans=0;
            int sum1 = min_heap.size();
            int sum2 = max_heap.size();
            int sum = sum1 + sum2;
            if(sum%2==0){
                int num1 = min_heap.top();
                int num2 = max_heap.top();
                ans = (num1 + num2) * 1.0 / 2;
            }
            else{
                if(sum1>sum2) ans=min_heap.top();
                else ans=max_heap.top();
            }
            cout <<fixed<<setprecision(1)<< ans << endl;
        }
       

    }

    return 0;
}
/*
- 使用一个heap很容易得知一定会爆的
- 这里尝试使用两个heap来解决
    - 两个heap分别对应arr的前半部分和后半部分
    - 前为maxheap，后面为minheap
    - 然后数量差值达到2的时候进行维护

- 反思：
    - 在设计算法的时候，要注意min_heap对应的是较大的那个数字
    - max_heap 对应的是较小的数字，min_heap对应的是较大的数字
    - 然后就是这个调整两个堆的算法了
    

    


*/