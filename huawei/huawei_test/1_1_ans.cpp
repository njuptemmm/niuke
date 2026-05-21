#include <bits/stdC++.h>
using namespace std;

static const double INF = 1e100;


double solve(int n, double T, const vector<vector<pair<double,double>>>& layers) {
    int S = 100;
    int W = (int)llround(T * S + 1e-9);

    vector<double> dp(W + 1, INF);
    dp[0] = 0.0;

    for (const auto& options : layers) {
        vector<double> ndp(W + 1, INF);

        for (int j = 0; j <= W; j++) {
            if (dp[j] >= INF / 2) continue;

            for (auto &op : options) {
                double loss = op.first;
                double mem  = op.second;

                int w = (int)llround(loss * S + 1e-9);
                int nj = j + w;
                if (nj <= W) {
                    double val = dp[j] + mem;
                    if (val < ndp[nj]) ndp[nj] = val;
                }
            }
        }

        
        dp.swap(ndp);
    }

    double ans = INF;
    for (int j = 0; j <= W; j++) ans = min(ans, dp[j]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double T;
    if (!(cin >> n >> T)) return 0;

    vector<vector<pair<double,double>>> layers;
    layers.reserve(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<pair<double,double>> opts;
        opts.reserve(k);

        for (int j = 0; j < k; j++) {
            string bit;    
            double loss, mem;
            cin >> bit >> loss >> mem;
            opts.push_back({loss, mem});
        }
        layers.push_back(opts);
    }

    double ans = solve(n, T, layers);
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << ans << "\n";
    return 0;
}
