#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;


    
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n+1, 0);
        vector<int> pred(n+1, 0);
        for (int i = 1; i <= n;i++){
            cin >> arr[i];
            if(i==1)
                pred[i] = arr[i];
            else
                pred[i] = pred[i - 1] + arr[i];
        }

        /*
        //构建分析体maxSum
        vector<vector<int>> maxSum;
        for(int i=1;i<n;)
        */


        while(m--){

            int l, r;
            cin >> l >> r;
            int sum1 = pred[r] - pred[l - 1];//计算机的结果是l到r所有的值
            int length = r - l + 1;

            //int flag = 0;
            //int ans = -INF;
            int maxLen = -1;
            int max_l=-1;
            int max_r=-1;

            //对于l左边的数组进行寻找：
            if(length<l){
                for (int i = length ; i < l;i++){
                    // maxLen = max(maxLen, pred[i] - pred[i - length]);
                    int sum=pred[i] - pred[i - length];
                    if(sum>maxLen){
                        maxLen = sum;
                        max_l = i - length+1;
                        max_r = i;
                    }
                }
            }
            //对于length右边的数组进行寻找
            if(n>=r+length){
                for (int i = r + 1; i <= n;i++){
                    //maxLen = max(maxLen, pred[i+length] - pred[i]);
                    int sum = pred[i+length] - pred[i];
                    if(sum>maxLen){
                        maxLen = sum;
                        max_l=i;
                        max_r = i + length;
                    }
                    
                }
            }
            //对于中间部分进行讨论
            if(n-length>length){
                for (int i = l - length+1; i < l;i++){
                    int sum = pred[l - 1] - pred[i - 1] + pred[r + l - i] - pred[r];
                    if(sum>maxLen){
                        maxLen=sum;
                        max_l=i;
                        max_r = r + l - i-length;
                    }
                    
                }
            }
            
            if(maxLen>sum1){
                cout << max_l << ' ' << max_r << endl;
            }
            else{
                cout << "-1"<<endl;
            }
            

        }
    }
    
    
    return 0;
}
/*
- 关于其中maxSum的创建思路
    - 使用maxsum[i][j]
        - i 位到i的值为止
        - j 表示length的长度


*/