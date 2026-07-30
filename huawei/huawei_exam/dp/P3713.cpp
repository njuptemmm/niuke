#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    cin >> text;
    int L = (int)text.size();

    int n;
    cin >> n;
    unordered_map<string, int> mp;                 // word -> its own value
    for (int i = 0; i < n; i++){
        string word; int p;
        cin >> word >> p;
        mp[word] = p;
    }

    int m;
    cin >> m;
    map<pair<string,string>, int> bonus;           // (prev word, cur word) -> bonus
    for (int i = 0; i < m; i++){
        string w1, w2; int num;
        cin >> w1 >> w2 >> num;
        bonus[{w1, w2}] = num;
    }

    const long long NEG = LLONG_MIN / 4;           // sentinel: state not reachable

    // dp[i]: after segmenting text[0..i-1], keyed by the LAST word placed,
    //        value = maximum total score of any valid segmentation ending with that word.
    // dp[0] is empty (no word placed yet) -> acts as the start state.
    vector<unordered_map<string, long long>> dp(L + 1);

    for (int i = 1; i <= L; i++){
        for (auto &op : mp){
            const string &w = op.first;
            long long v = op.second;
            int len = (int)w.size();
            if (len > i) continue;                          // word longer than the prefix
            if (text.substr(i - len, len) != w) continue;   // word must match the end of the prefix
            int start = i - len;                            // start index of w in text

            long long best = NEG;
            if (start == 0){
                best = v;                                   // first word: no predecessor, no bonus
            } else {
                // previous word must end exactly at `start`, i.e. come from dp[start]
                for (auto &opt : dp[start]){
                    const string &pw = opt.first;           // previous word
                    long long cand = opt.second + v;        // prev total + value of current word
                    auto it = bonus.find({pw, w});
                    if (it != bonus.end()) cand += it->second;  // adjacency bonus
                    best = max(best, cand);
                }
            }
            if (best != NEG){
                auto it = dp[i].find(w);
                if (it == dp[i].end()) dp[i].emplace(w, best);
                else if (it->second < best) it->second = best;
            }
        }
    }

    long long ans = NEG;
    for (auto &op : dp[L]) ans = max(ans, op.second);
    if (ans == NEG) ans = 0;        // no way to cover the whole text
    cout << ans << "\n";
    return 0;
}
