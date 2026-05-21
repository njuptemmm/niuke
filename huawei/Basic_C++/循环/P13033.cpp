#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> xu;
    int max = 0;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        if(max<num){
            max = num;
            xu.clear();
            xu.push_back(i);
        }
        else{
            if(max==num){
                xu.push_back(i);
            }
        } 
    }
    cout << max << endl;
    for (int i = 0; i < xu.size();i++){
        cout << xu.at(i)<<" ";
    }
    return 0;
}