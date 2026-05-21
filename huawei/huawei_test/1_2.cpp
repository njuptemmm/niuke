// P4274：题意对应说明（实现与全文一致）
// 1）「每个位置的能量值 = 策略矩阵与该位置周边信号值的乘积和」：以该像素为中心将 K×K 策略与图像对齐，
//    每个策略元素乘对应格上的信号（图像外视为 0），再全部相加，记为 E[i][j]。
// 2）题首「路径上……乘积之和」在给出上式后，应理解为：沿路径把经过的每个格子的「能量值 E」累加求和（而非把 map 原值直接相加）。
// 3）「第一列任意出发 → 最后一列任意结束；每步右、右上、右下」：列号 j 从 1 走到 W；
//    若 map[i][j] 为第 i 行第 j 列，则从 (i,j) 可到 (i,j+1)、(i-1,j+1)、(i+1,j+1)。
#include <bits/stdc++.h>
using namespace std;

static const double NEG = -1e200;

// [修正·对应题意] 计算「以 (row,col) 为中心」的能量：周边信号与策略矩阵逐项乘积之和；越界处信号为 0。
// 原代码用图像下标去取 arr、且 x_count/y_count 未声明；此处改为策略下标 (si,sj) 与图像 (ii,jj) 一一对齐。
//首先就是在energy这个中间，要清楚：核和map对应的值是不一样的
double energyAt(const vector<vector<double>>& img, const vector<vector<double>>& ker,
                int row, int col, int kr, int kc, int h, int w) {
    double sum = 0.0;
    int cr = (kr + 1) / 2;  // 策略矩阵中心（1-based，K 为奇数）
    int cc = (kc + 1) / 2;
    for (int si = 1; si <= kr; ++si) {
        for (int sj = 1; sj <= kc; ++sj) {
            int ii = row + si - cr;
            int jj = col + sj - cc;
            double sig = 0.0;
            if (ii >= 1 && ii <= h && jj >= 1 && jj <= w)
                sig = img[ii][jj];
            sum += sig * ker[si][sj];
        }
    }
    return sum;
}

// [修正·对应题意] dp[i][j]：从第 1 列某格出发、走到 (i,j) 时，路径上收集的能量之和最大是多少。
double solve(const vector<vector<double>>& img, const vector<vector<double>>& ker,
             int h, int w, int kr, int kc) {
    vector<vector<double>> E(h + 1, vector<double>(w + 1, 0.0));
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            E[i][j] = energyAt(img, ker, i, j, kr, kc, h, w);

    vector<vector<double>> dp(h + 1, vector<double>(w + 1, NEG));

    //这里我们使用的是列式操作：主要是因为在我们的实现中，我们是一列一列从左到右开始进行处理的
    for (int j = 1; j <= w; ++j) {
        for (int i = 1; i <= h; ++i) {
            if (j == 1) {
                // [修正] 第一列只能「从本格开始」，不能把「第 0 列的 0」当成合法前驱。
                dp[i][j] = E[i][j];
            } else {
                double best = NEG;
                if (i > 1) best = max(best, dp[i - 1][j - 1]);   // 从左上一步「右下」走来
                best = max(best, dp[i][j - 1]);                   // 从左一步「右」走来
                if (i < h) best = max(best, dp[i + 1][j - 1]);     // 从左下一步「右上」走来
                // [修正] 收集的是「能量」E[i][j]，不是原始信号 img[i][j]。
                dp[i][j] = E[i][j] + best;
            }
        }
    }

    // [修正] 终点是「最后一列任意行」；result 须初始化，且应对所有 i 取 max，不能只用第 h 行。
    double ans = NEG;
    for (int i = 1; i <= h; ++i)
        ans = max(ans, dp[i][w]);
    return ans;
}

int main() {
    int h, w, k1, k2;
    cin >> h >> w >> k1 >> k2;
    vector<vector<double>> img(h + 2, vector<double>(w + 2, 0.0));
    vector<vector<double>> ker(k1 + 2, vector<double>(k2 + 2, 0.0));

    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> img[i][j];

    for (int i = 1; i <= k1; ++i)
        for (int j = 1; j <= k2; ++j)
            cin >> ker[i][j];

    double out = solve(img, ker, h, w, k1, k2);
    cout << fixed << setprecision(1) << out << endl;
    return 0;
}
