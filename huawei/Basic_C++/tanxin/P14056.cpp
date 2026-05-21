#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> rack(n + 1);
    
    for (int i = 1; i <= n;i++){
        cin >> rack[i];
    }

    //对于每一个分段进行处理
    int left = 1;
    int min_value = INF;
    int ans = 0;//用来计算ans使用到的时间；
    bool flag = true;
    while(flag){
        flag = false;
        for (int right = 1; right <= n;right++){
            if(rack[right]==0){
                if(left==right){
                    continue;
                }
                else if(right==left+1){//说明是遇到了仅仅只有一个数值的情况，这个时候应该就要终止了
                    rack[left] = 0;
                    ans += 2;
                    flag = true;
                }
                else{
                    ans++;
                    flag = true;
                    for (int i = left; i <= right;i++){
                        rack[i] -= min_value;
                    }
                    min_value = INF;
                }
            }
            min_value = min(min_value, rack[right]);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
- 也就是说是任意柱子之间是要不连续的，我们然后才进行柱子的更新？
- 对于每一个连续的部分来说，维护一个min
- 个人的想法其实是偏向于使用暴力了
*/