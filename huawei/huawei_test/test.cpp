#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

// 用于保存一个样本
struct Sample {
    long double x1;
    long double x2;
    long double yTrue;
};

// 用于返回最终参数结果
struct Result {
    long double w1;
    long double w2;
    long double b;
};

// 按题意执行 AdamW 更新，返回最终的 w1、w2、b
Result adamwTrain(const vector<Sample>& samples) {
    // 题目给定的超参数
    const long double beta1 = 0.9L;
    const long double beta2 = 0.999L;
    const long double weightDecay = 0.01L;
    const long double lr = 0.001L;
    const long double eps = 1e-8L;

    // 参数初始化
    long double w1 = 0.0L;
    long double w2 = 0.0L;
    long double b = 0.0L;

    // 一阶动量初始化
    long double mW1 = 0.0L;
    long double mW2 = 0.0L;
    long double mB = 0.0L;

    // 二阶动量初始化
    long double vW1 = 0.0L;
    long double vW2 = 0.0L;
    long double vB = 0.0L;

    // 按样本顺序逐个更新
    for (int i = 0; i < (int)samples.size(); i++) {
        int t = i + 1;
        long double x1 = samples[i].x1;
        long double x2 = samples[i].x2;
        long double yTrue = samples[i].yTrue;

        // 当前样本的预测值
        long double yPred = w1 * x1 + w2 * x2 + b;

        // 当前样本的误差
        long double error = yPred - yTrue;

        // 按题目公式计算梯度
        long double gW1 = 2.0L * error * x1;
        long double gW2 = 2.0L * error * x2;
        long double gB = 2.0L * error;

        // 更新一阶动量
        mW1 = beta1 * mW1 + (1.0L - beta1) * gW1;
        mW2 = beta1 * mW2 + (1.0L - beta1) * gW2;
        mB = beta1 * mB + (1.0L - beta1) * gB;

        // 更新二阶动量
        vW1 = beta2 * vW1 + (1.0L - beta2) * gW1 * gW1;
        vW2 = beta2 * vW2 + (1.0L - beta2) * gW2 * gW2;
        vB = beta2 * vB + (1.0L - beta2) * gB * gB;

        // 偏差修正
        long double mW1Hat = mW1 / (1.0L - powl(beta1, t));
        long double mW2Hat = mW2 / (1.0L - powl(beta1, t));
        long double mBHat = mB / (1.0L - powl(beta1, t));

        long double vW1Hat = vW1 / (1.0L - powl(beta2, t));
        long double vW2Hat = vW2 / (1.0L - powl(beta2, t));
        long double vBHat = vB / (1.0L - powl(beta2, t));

        // 按题目给定的 AdamW 公式更新参数
        w1 = w1 - lr * (mW1Hat / (sqrtl(vW1Hat) + eps) + weightDecay * w1);
        w2 = w2 - lr * (mW2Hat / (sqrtl(vW2Hat) + eps) + weightDecay * w2);
        b = b - lr * (mBHat / (sqrtl(vBHat) + eps) + weightDecay * b);
    }

    return {w1, w2, b};
}

// 银行家舍入到 6 位小数
string formatBankers(long double value) {
    long double scaled = value * 1000000.0L;
    long double floorVal = floorl(scaled);//向下取整,在double中我们使用的是floor
    long double diff = scaled - floorVal;//计算小数部分
    long long base = (long long)floorVal;//转完成证书，用于后面的取模运算
    const long double tiny = 1e-12L;

    //此时的scaled存储的是整数部分
    // 小于 0.5，直接舍去
    if (diff < 0.5L - tiny) {
        scaled = floorVal;
    }
    // 大于 0.5，直接进位
    else if (diff > 0.5L + tiny) {
        scaled = floorVal + 1.0L;
    }
    // 等于 0.5，按银行家舍入，看前一位是否为偶数
    else {
        if (base % 2 == 0) {
            scaled = floorVal;
        } else {
            scaled = floorVal + 1.0L;
        }
    }

    long double ans = scaled / 1000000.0L;

    ostringstream out;
    out << fixed << setprecision(6) << (double)ans;
    return out.str();
}







int main() {
    int n;
    cin >> n;

    vector<Sample> samples(n);
    for (int i = 0; i < n; i++) {
        cin >> samples[i].x1 >> samples[i].x2 >> samples[i].yTrue;
    }

    Result ans = adamwTrain(samples);
    cout << formatBankers(ans.w1) << " "
         << formatBankers(ans.w2) << " "
         << formatBankers(ans.b) << "\n";

    return 0;
}
