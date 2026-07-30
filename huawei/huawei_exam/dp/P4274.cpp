#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k1, k;
    cin >> h >> w >> k >> k1;
    vector<vector<int>> arr(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> juan(k + 1, vector<int>(k + 1, 0));
    vector<vector<double>> energy(h + 1, vector<double>(w + 1, 0));
    

    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= k;i++){
        for (int j = 1; j <= k;j++){
            cin >> juan[i][j];
        }
    }

    int mid = (k + 1) / 2;
    for (int i1 = 1; i1 <= h;i1++){
        for (int j1 = 1; j1 <= w;j1++){
            //对于第i1，j1的点进行处理
            double num = 0.0;
            for (int i = 1; i <= k;i++){
                for (int j = 1; j <= k;j++){
                    int ii = i1 + i - mid;
                    int jj = j1 + j - mid;
                    if (ii <= 0 || ii > h || jj <= 0||jj>w) continue;
                    else
                        num += juan[i][j] * arr[ii][jj];
                }
            }
            energy[i1][j1] = num;
        }
    }

    vector<vector<double>> dp(h + 5, vector<double>(w + 5, -INF)); //用来存储所有的权值

    //dp[i][j]: 在位置(i,j)上面的值
    for (int i = 1; i <= h;i++){
        dp[i][1] = energy[i][1];
    }


    //主要就是这个二重循环的部分出现问题。对这个顺序是重要的，因为我们要对于每一列的情况进行讨论和分析
    //如果说二者的先后顺序发生改变那么会导致相关的数值已经发生变化从而导致失败
     for (int j = 2; j <= w; ++j) {
        for (int i = 1; i <= h; ++i) {
            double best = dp[i][j - 1];                       // 从左边来
            if (i > 1) best = max(best, dp[i - 1][j - 1]);   // 从左上
            if (i < h) best = max(best, dp[i + 1][j - 1]);   // 从左下
            dp[i][j] = best + energy[i][j];
        }
    }

    double ans=-INF;
    for (int i = 1; i <= h;i++){
        ans = max(ans, dp[i][w]);
    }

    cout.setf(std::ios::fixed); 
    cout <<setprecision(1) <<  ans << "\n";


    return 0;
}
