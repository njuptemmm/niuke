#include<bits/stdc++.h>
using namespace std;

int n;
long long t;
const int INF = 1e9 + 7;

// ¶þ·ÖÅÐ¶Ï
bool check(vector<long long> &s,vector<int> &d,int mid){
    long long cur = 0;
    for (int i = 0;i<n;i++){
        if(d[i]>mid){
            cur = 0;
            continue;
        }
        cur += s[i];
        if(cur>=t){
            return true;
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    vector<long long> s(n);
    vector<int> d(n);
    for (int i = 0; i < n;i++){
        cin >> s[i] >> d[i];
    }
    int left=1;
    int right = INF;
    int mid;
    while(right>left){
        mid=(left+right)/2;
        if(check(s,d,mid)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << mid << endl;
    return 0;
}