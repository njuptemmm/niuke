//P3713

//思路：使用unordered_map 将字符与数值结合
//之后使用遍历对于后面输入的进行分析

#include<bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int main(){

    string text;
    cin >> text;

    int n;
    cin >> n;
    int maxLength = 0;
    unordered_map<string, int> words;
    for (int i = 1; i <= n;i++){
        string w;
        int val;
        cin >> w >> val;
        words[w] = val;
        maxLength = max(maxLength, (int)w.size());
    }

    int m;
    cin>>m;
    unordered_map<string,unordered_map<string,int>> bouns;
    for (int i = 1; i <= m;i++){
        string w1;
        string w2;
        int val;
        cin >> w1 >> w2 >> val;
        bouns[w1][w2] = val;
    }

    int Length = (int)text.size();

    //我们使用的dp不仅仅要存储前i个dp的结果，同时也要处理结尾的单词string
    vector<unordered_map<string, int>> dp(Length+1);

    //对于前i的情况进行dp讨论
    //这里dp是分为两层的：dp[i]指的是第i张表
    //unordered_map<string, int>指的是string:结尾词；int以该词结尾的时候达到的最大值
    for (int i = 1; i <= Length;i++){
        //一个word合适的长度
        int up = min(i, maxLength);

        for (int len = 1; len <= up;len++){
            //对于前i从后遍历所有的结尾单词情况
            string w = text.substr(i - len, len);
            auto it1 = words.find(w);
            if(it1==words.end()){
                continue;
            }
            //对于接触的到的词语给出基础情况
            int base = it1->second;

            //j表示除去这个单词的长度；
            int j = i - len;
            if(j==0){//表示没有情况了
                auto it = dp[i].find(w);
                if(it==dp[i].end())
                    dp[i][w] = base;
                else
                    it->second = max(it->second, base);
            }
            else{
                if(dp[j].empty()){
                    continue;
                }
                for(auto& opt:dp[j]){
                    //在 dp[j]的情况下，当前数值和last word
                    string opt_w = opt.first;
                    int opt_v = opt.second;
                    
                    int add = 0;
                    //先寻找的是答案前面的词
                    auto itu = bouns.find(opt_w);
                    if(itu!=bouns.end()){
                        auto itv = itu->second.find(w);
                        if(itv!=itu->second.end()){
                            add = itv->second;
                        }
                    }
                    int cand = opt_v + base + add;
                    auto it = dp[i].find(w);
                    //在同一个dp[i]中没有这样的数据的时候
                    if(it==dp[i].end())
                        dp[i][w] = cand;
                    else
                        it->second = max(it->second, cand);
                }
            }
        }

    }

    int L = text.size();
    if(dp[L].empty()){
        cout << 0 << endl;
    }
    else{
        int ans = -INF;
        for(auto& pr:dp[L])
            ans = max(ans, pr.second);
        cout << ans << endl;
    }

    return 0;
}