//本题对于时间复杂度没有要求，所以说本题能够轻松解答
//实际上我们是要使用单调栈的来储存右侧最大的数字，在使用一个序号栈来同步存储其的序号来实现
//我是有想要这样解答，但是想象要同时管两个栈就没有了解了
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int value(int n){
    int sum = 0;
    while(n>0){
        sum += n % 16;
        n /= 16;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    while(n--){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    //计算权重
    vector<int> v;
    for (int i = 0; i < arr.size();i++){
        int num=value(arr[i]);
        v.push_back(num);
    }

    //答案序列
    vector<int> ans;
    
    for (int i = 0; i < v.size();i++){
        if(i==v.size()-1){
            ans.push_back(-1);
            break;
        }
            
        for (int j = i + 1; j < v.size();j++){
            if(v[j]>v[i]){
                ans.push_back(j);
                break;
            }
            if(j==v.size()-1){
                ans.push_back(-1);
            }
        }
    }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    cout << endl;
    return 0;
}