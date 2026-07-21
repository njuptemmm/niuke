#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int, int> counts;
    vector<int> arr;
    for (int i = 0; i < n;i++){
        int val;
        cin >> val;
        counts[val]++;
    }

    int premex=0;
    long long sum=0;
    bool flag=true;//说明当前是否海被mex控制
    //如果flag=false说明之前存在缺口导致premex的值不再变化

    for (auto it = counts.begin(); it != counts.end();++it){
        if(it->second>0){
            int num = it->first;
            if(flag){
                if(num==premex){
                    premex++;
                    sum += premex;
                }
                if(num>premex){
                    sum+=premex;
                    flag = false;
                }
            }
            else{
                sum += premex;
            }
            counts[num]--;
            arr.push_back(num);
        }
    }
    for(auto it = counts.begin(); it != counts.end();++it){
        if(it->second>0){
            while(it->second--){
                arr.push_back(it->first);
                sum += premex;
            }
        }
    }

    cout << sum << endl;
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
/*
- 原来印象中是有有一个算法可以实现对于数据进行处理能够自动将重复的部分补充到后面
- 但是现在发现没有那还是使用map了

- 对于我们使用到的map场景，我们还是需要进一步了解相关tools的使用方法
*/