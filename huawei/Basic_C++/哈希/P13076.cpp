
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}

int main(){
    unordered_map<int, vector<int>> arr;
    vector<int> nums;
    int sum;
    cin >> sum;
    for (int i = 1; i <= sum;i++){
        int num;
        cin >> num;
        arr[i - num].push_back(i);
        nums.push_back(num);
    }

    int count = 0;//用来计算所有满足条件的对子的数量
    int count_0 = 0;//用来计算所有满足条件的对子的数量

    for (int i = 1; i <= sum;i++){

        //查询的是这个差值n的所对应的hash表；
        //所以我们针对于这个hash进行搜索操作
        //现在的问题在于其中的0上面？
        int n = nums[i-1] - i;
        if(arr.find(n)==arr.end()){
            continue;
        }
        else{
            int c = 0;
            for (int j = 0; j <=min(i-1,arr[n].size()-1);j++){
                if(arr[n][j]<=i){
                    c++;
                }
            }
            count += c;
        }
        
    }
    cout << count << endl;
    return 0;
}
/*
我整体的思路是使用map存储对应插值的位置，之后使用键值对不断进行遍历

但是我们处理的时候其实得出差值value和次数的关系就可以解决了

*/