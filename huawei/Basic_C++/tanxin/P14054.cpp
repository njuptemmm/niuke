#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    int max_value = -1;
    int min_value = -1;
    for (int i = 1; i <= n; i++){
        if (max_value == -1 && min_value == -1){
            sum++;
            max_value = arr[i];
            min_value = arr[i];
            continue;
        }
        // 先计算加入当前物品后的新极值
        int new_max = max(max_value, arr[i]);
        int new_min = min(min_value, arr[i]);
        if (new_max - new_min > k){
            // 不能加入当前组，新开一组，当前物品作为新组的第一个
            sum++;
            max_value = arr[i];
            min_value = arr[i];
        } else {
            max_value = new_max;
            min_value = new_min;
        }
    }
    cout << sum << endl;
    return 0;
}
