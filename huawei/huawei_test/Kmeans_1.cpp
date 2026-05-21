#include <bits/stdc++.h>
using namespace std;

double iouWH(double w1, double h1, double w2, double h2) {
    double inter = min(w1, w2) * min(h1, h2);
    double uni = w1 * h1 + w2 * h2 - inter;
    return inter / (uni + 1e-16);
}

int main() {
    int N, K, T;
    cin >> N >> K >> T;
    
    vector<double> x(N), y(N);
    vector<double> cx(K), cy(K);
    
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    // 稳定初始化：取前K个框作为初始中心
    for (int k = 0; k < K; k++) {
        cx[k] = x[k];
        cy[k] = y[k];
    }
    
    vector<int> lab(N);
    
    for (int t = 0; t < T; t++) {
        // 分配阶段
        for (int i = 0; i < N; i++) {
            int bestK = 0;
            double bestD = 1.0 - iouWH(x[i], y[i], cx[0], cy[0]);
            for (int k = 1; k < K; k++) {
                double d = 1.0 - iouWH(x[i], y[i], cx[k], cy[k]);
                if (d < bestD) {
                    bestD = d;
                    bestK = k;
                }
            }
            lab[i] = bestK;
        }
        
        // 更新阶段：先计算新中心
        vector<double> new_cx(K), new_cy(K);
        vector<int> cnt(K, 0);
        vector<double> sumW(K, 0.0), sumH(K, 0.0);
        
        // 统计每个簇的宽高总和
        for (int i = 0; i < N; i++) {
            int k = lab[i];
            sumW[k] += x[i];
            sumH[k] += y[i];
            cnt[k]++;
        }
        
        // 计算新中心（向下取整）
        for (int k = 0; k < K; k++) {
            if (cnt[k] > 0) {
                new_cx[k] = floor(sumW[k] / cnt[k]);
                new_cy[k] = floor(sumH[k] / cnt[k]);
            } else {
                // 空簇：保持原中心不变
                new_cx[k] = cx[k];
                new_cy[k] = cy[k];
            }
        }
        
        // 计算新旧中心距离变化
        double change = 0.0;
        for (int k = 0; k < K; k++) {
            change += (1.0 - iouWH(cx[k], cy[k], new_cx[k], new_cy[k]));
        }
        
        // 更新中心
        cx = new_cx;
        cy = new_cy;
        
        // 检查终止条件
        if (change < 1e-4) {
            break;
        }
    }
    
    // 准备输出结果
    vector<pair<int, int>> ans(K);
    for (int i = 0; i < K; i++) {
        ans[i] = { (int)cx[i], (int)cy[i] };
    }
    
    // 按面积从大到小排序
    sort(ans.begin(), ans.end(), [](auto& a, auto& b) {
        long long area_a = 1LL * a.first * a.second;
        long long area_b = 1LL * b.first * b.second;
        if (area_a != area_b) {
            return area_a > area_b;
        }
        // 面积相同时，按宽降序（可选）
        return a.first > b.first;
    });
    
    // 输出结果
    for (int i = 0; i < K; i++) {
        cout << ans[i].first << " " << ans[i].second;
        if (i < K - 1) cout << "\n";
    }
    
    return 0;
}
