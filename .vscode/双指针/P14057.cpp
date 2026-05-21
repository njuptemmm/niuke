#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a_guan(n, 0);
    vector<int> b_guan(n, 0);
    for (int i = 0; i < n;i++){
        int num;
        cin >> a_guan[i];
    }
    for (int i = 0; i < n;i++){
        int num;
        cin >> b_guan[i];
    }
    vector<int> a_add(n-1,0);
    vector<int> b_add(n - 1, 0);
    for (int i = 0; i < n - 1;i++){
        a_add[i] = a_guan[i + 1] - a_guan[i];
    }
    for (int i = 0; i < n - 1;i++){
        b_add[i] = b_guan[i + 1] - b_guan[i];
    }

    int left = 0;
    int max_len = -1;
    bool flag = false;
    for (int right = 0; right < n-1;right++){
        if(a_add[right]==b_add[right]){
            flag = true;
            max_len = max(max_len, right - left + 1);
        }
        else{
            left = right + 1;
        }
    }
    if(flag) max_len++;
    else
        max_len = 1;
    cout << max_len << endl;
}