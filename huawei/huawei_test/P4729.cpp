#include<bits/stdc++.h>
using namespace std;

//特征归一化



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, N;
    double alpha;
    cin >> m >> N >> alpha;
    vector<vector<double>> arr(m,vector<double>(4,-1));
    for (int i = 0; i < m;i++){
        for (int j = 0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    vector<double> w(4, 0);//初始的偏置值

    //特征归一化
    for(int i)
}