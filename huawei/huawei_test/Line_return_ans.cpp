#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    
    // 读取训练数据
    vector<vector<double>> X(K, vector<double>(4, 1.0));  // 第一列为1（偏置项）
    vector<double> Y(K);
    
    for (int i = 0; i < K; i++) {
        double x1, x2, x3, y;
        cin >> x1 >> x2 >> x3 >> y;
        X[i][1] = x1;
        X[i][2] = x2;
        X[i][3] = x3;
        Y[i] = y;
    }
    
    // 计算 X^T * X 和 X^T * Y
    double XT_X[4][4] = {0};
    double XT_Y[4] = {0};
    
    for (int i = 0; i < K; i++) {
        for (int a = 0; a < 4; a++) {
            XT_Y[a] += X[i][a] * Y[i];
            for (int b = 0; b < 4; b++) {
                XT_X[a][b] += X[i][a] * X[i][b];
            }
        }
    }
    
    // 构造增广矩阵 [XT_X | XT_Y]
    double A[4][5];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = XT_X[i][j];
        }
        A[i][4] = XT_Y[i];
    }
    
    // 高斯消元求解 W
    for (int i = 0; i < 4; i++) {
        // 归一化当前行
        double pivot = A[i][i];
        for (int j = i; j < 5; j++) {
            A[i][j] /= pivot;
        }
        
        // 消去其他行的第i列
        for (int k = 0; k < 4; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < 5; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    
    // 提取权重参数 W
    double W[4];
    for (int i = 0; i < 4; i++) {
        W[i] = A[i][4];
    }
    
    // 读取待预测数据
    int N;
    cin >> N;
    
    vector<long long> results;
    for (int i = 0; i < N; i++) {
        double x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        
        // 计算预测价格: y = w0 + w1*x1 + w2*x2 + w3*x3
        double price = W[0] + W[1] * x1 + W[2] * x2 + W[3] * x3;
        
        // 四舍五入取整
        results.push_back(llround(price));
    }
    
    // 输出结果
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << results[i];
    }
    
    return 0;
}
