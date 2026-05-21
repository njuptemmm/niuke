//使用vector进行实现
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    long long left_sum = 0, right_sum = 0;
    cin >> n >> m;
    vector<int> left(n);
    vector<int> right(m);
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        left.push_back(num);
    }
    for (int i = 0; i < m;i++){
        int num;
        cin >> num;
        right.push_back(num);
    }
    for(int weight:left){
        left_sum += weight;
    }
    for(int weight:right){
        right_sum += weight;
    }
    if(right_sum == left_sum)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    return 0;
}