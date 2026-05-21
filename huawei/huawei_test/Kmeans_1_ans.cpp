#include <bits/stdc++.h>
using namespace std;

// 计算两个宽高框的 IOU
double iouWH(double w1, double h1, double w2, double h2) {
    double inter = min(w1, w2) * min(h1, h2);
    double uni = w1 * h1 + w2 * h2 - inter;
    return inter / (uni + 1e-16);
}

// d = 1 - IOU 的 K-means 聚类
vector<pair<int,int>> kmeansAnchors(const vector<pair<double,double>>& boxes, int K, int T) {
    int N = (int)boxes.size();
    // 初始化：前 K 个样本
    vector<pair<double,double>> centers(K);
    for (int k = 0; k < K; ++k) centers[k] = boxes[k];

    for (int t = 0; t < T; ++t) {
        // 分配阶段
        vector<int> assign(N, 0);
        for (int i = 0; i < N; ++i) {
            double w = boxes[i].first, h = boxes[i].second;
            int bestK = 0;
            double bestD = 1.0 - iouWH(w, h, centers[0].first, centers[0].second);
            for (int k = 1; k < K; ++k) {
                double d = 1.0 - iouWH(w, h, centers[k].first, centers[k].second);
                if (d < bestD) {
                    bestD = d;
                    bestK = k;
                }
            }
            assign[i] = bestK;
        }

        // 更新阶段
        vector<double> sumW(K, 0.0), sumH(K, 0.0);
        vector<int> cnt(K, 0);
        for (int i = 0; i < N; ++i) {
            int k = assign[i];
            sumW[k] += boxes[i].first;
            sumH[k] += boxes[i].second;
            cnt[k] += 1;
        }
        vector<pair<double,double>> newCenters(K);
        for (int k = 0; k < K; ++k) {
            if (cnt[k] == 0) {
                // 空簇，保持不变
                newCenters[k] = centers[k];
            } else {
                double W = floor(sumW[k] / cnt[k]);
                double H = floor(sumH[k] / cnt[k]);
                newCenters[k] = {W, H};
            }
        }

        // 终止条件
        double change = 0.0;
        for (int k = 0; k < K; ++k) {
            change += (1.0 - iouWH(centers[k].first, centers[k].second,
                                   newCenters[k].first, newCenters[k].second));
        }
        centers.swap(newCenters);
        if (change < 1e-4) break;
    }

    // 最终向下取整并按面积从大到小排序
    vector<pair<int,int>> ans;
    ans.reserve(K);
    for (int k = 0; k < K; ++k) {
        int W = (int)floor(centers[k].first);
        int H = (int)floor(centers[k].second);
        ans.emplace_back(W, H);
    }
    sort(ans.begin(), ans.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        long long A = 1LL * a.first * a.second;
        long long B = 1LL * b.first * b.second;
        if (A != B) return A > B;               // 面积降序
        if (a.first != b.first) return a.first > b.first; // 次级规则（可选）
        return a.second > b.second;
    });
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, T;
    if (!(cin >> N >> K >> T)) return 0;
    vector<pair<double,double>> boxes(N);
    for (int i = 0; i < N; ++i) {
        cin >> boxes[i].first >> boxes[i].second;
    }
    auto centers = kmeansAnchors(boxes, K, T);
    for (int i = 0; i < (int)centers.size(); ++i) {
        cout << centers[i].first << " " << centers[i].second;
        if (i + 1 < (int)centers.size()) cout << "\n";
    }
    return 0;
}
