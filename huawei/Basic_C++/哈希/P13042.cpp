#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}

using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<int, vector<int>> arr;
    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        arr[num].push_back(i);
    }

    for (int i = 1; i <= n;i++){
        if(arr.find(i)==arr.end()){
            cout << 0 << " ";
        }
        else{
            int count = 0;
            for (int j = 0; j <= min(i-1,arr[i].size()-1);j++){
                if(arr[i][j]<=i){
                    count++;
                }
            }
            cout << count << " ";
        }
    }
    cout << endl;
    return 0;
}