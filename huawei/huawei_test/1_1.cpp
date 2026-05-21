//https://codefun2000.com/p/P4568
//
#include<bits/stdc++.h>
using namespace std;

static const double INF = 1e100;

double solve(int n,double T,const vector<vector<pair<double,double>>> layers){
    int S = 100;
    int W = T * S;

    //dp[j]:总损失为j的时候，我们所有的最小内存
    vector<double> dp(W + 1, INF);//在所有的情况中：一共要考虑0~W的情况
    //这一句的含义是：在原始的dp，所有mem占用都是INF->不可能的解
    //这个INF我们看我们的const可以知道其代表的是一个极大的值->代表极大的解

    dp[0] = 0.0;

    for(auto& opts:layers){
        vector<double> ndp(W + 1, INF);
        // 这一步要结合最后的dp.sawp(ndp);一起讨论:
        // ndp和dp储存的内容都是一样的
        // ndp是在这一个layer中推进的结果,dp是整体的结果;
        // 最后用dp.swap(ndp)dp获得了更新之后的数据,ndp获得了跟新之前的数据;

        for (int j = 0; j <= W;j++){//使用j来遍历所有容量的情况
            if(dp[j]>=INF/2) continue;//排除掉此时的不可能情况

            //递归公式是:ndp[j+w]=min(ndp[j+w],dp[j]+mem)//其实就是要么保持不变，要么产生什么样子的变化
            for (auto &op : opts)
            {
                double loss = op.first;
                double mem = op.second;
                int w = loss * S;
                int nj = j + w;
                if(nj<=W){
                    double val = dp[j] + mem;
                    if(val<ndp[nj])
                        ndp[nj] = val;
                }
            }
        }
        dp.swap(ndp);
    }

    double ans = INF;
    for (int j = 0; j <= W;j++)
        ans = min(ans, dp[j]);
    // 对于所有的阈值T对应的W,找出mem最小的ans;

    return ans;
}

int main(){
    int n;
    double T;
    cin >> n >> T;
    //用来存储每一层所有的相关信息
    vector<vector<pair<double,double>>> layers;

    for (int j = 1; j <= n;j++){
        int K;
        cin >> K;
        //使用opts存储当前层中所有的可能
        vector<pair<double,double>>opts;
        opts.reserve(K);
        for (int i = 1; i <= K;i++){
            string str;
            double loss, mem;
            cin >> str >> loss >> mem;
            opts.push_back({loss, mem});
        }
        layers.push_back(opts);
    }
    double ans = solve(n, T, layers);
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}

//
/*
本题算是第一题认真完成的dp题目
主要的经验就是：确定是在不超过什么的阈值下，获取什么的min值/max值
其实从整体来说，难度并不是很高，但是认真吃透还是有必要的
*/