#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> cnt2(n, 0);
    vector<int> cnt5(n, 0);
    vector<int> arr(n,0);

    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
        while(num%2==0){
            cnt2[i]++;
            num/=2;
        }
        while(num%5==0){
            cnt5[i]++;
            num/=5;
        }
    }
    int left = 0;
    int count = 0;
    int count_2 = 0;
    int count_5 = 0;
    int right = 0;
     for (int left = 0; left < n; left++) {
        // 扩展右端点，直到满足条件或到达末尾
        while (right < n && (count_2 < k || count_5 < k)) {
            count_2 += cnt2[right];
            count_5 += cnt5[right];
            right++;
        }
        
        // 如果满足条件，计算以 left 为起点的合法子数组个数
        if (count_2 >= k && count_5 >= k) {
            count += (n - right + 1);
        }
        
        // 移动左端点，减去对应的计数
        count_2 -= cnt2[left];
        count_5 -= cnt5[left];
    }
    
    cout << count << endl;
    return 0;
}