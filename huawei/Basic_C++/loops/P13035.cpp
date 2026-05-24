#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n+1,vector<int>(m+1,0));
    for (int i = 1; i < n+1;i++){
        for (int j = 1; j < m+1;j++){
            int num;
            cin >> num;
            nums[i][j] = num;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int max = 0;
        for (int i = x1; i <= x2;i++){
            for (int j = y1; j <= y2;j++){
                int num = nums[i][j];
                if(max<num){
                    max = num;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}