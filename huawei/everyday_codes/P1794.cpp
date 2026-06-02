#include<bits/stdc++.h>
using namespace std;
int main(){

    int n ;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    vector<int> choices(n + 1);
    int left = 1;
    //int value=-1;
    vector<int> count;
    int count_sum = 0;
    for (int right = 1; right <= n;right++){
        if(right==-1){
            continue;
        }
        //如果与前面的值是一样的
        //arr[left]指代的是前面最小值
        if(arr[right]==arr[left]){
            count.push_back(left);
            choices[left] = right - left;
            count_sum += choices[left];
            left = right;
        }
        //需要进行更新
        if(arr[right]<arr[left]){
            count.push_back(left);
            choices[left] = right - left;
            count_sum += choices[left];
            left = right;
            //处理前面可能存在的连续情况
            int avg = count_sum / count.size();
            if(count_sum%count.size()!=0){
                avg++;
            }
            for (int i = 0; i < count.size();i++){
                if(i!=count.size()-1){
                    int node = arr[count[i]];
                    choices[node] = avg;
                    count_sum -= avg;
                }
                else{
                    int node = arr[count[i]];
                    choices[node] = count_sum;
                }
            }
            //清空存储数值的count
            count.clear();
            count_sum = 0;
        }
        if(right==n){//处理最后的情况
            choices[left] = right - left;
        }
    }
    for (int i = 1; i <= n;i++){
        cout << choices[i] << ' ';
    }
    return 0;
}
/*
- 这个是原来的思路：单纯是使用了
- 对于left的值，当前node中如果value比其更小则终止并且更换value
- 使用简单的替换处理不能解决这个问题
- 对于小于的部分不用判断，对于等于的情况需要进行特判
- 并且是要对于连在一起的部分要进行平均？
- 单纯引入之后感觉还是不行
- 我觉得可以尝试将choices选择数组中间的存储格式更换成其他的格式？？

*/