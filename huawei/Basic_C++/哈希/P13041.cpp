#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    unordered_map<int, vector<int>> arr;

    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        arr[num].push_back(i);
    }

    while(q--){
        int x, k;
        cin >> x >> k;
        if(arr.find(x)==arr.end()){
            cout << -1 << endl;
            continue;
        }
        else{
            if(k>arr[x].size()){
                cout << -1 << endl;
                continue;
            }
            else{
                cout << arr[x].at(k-1) << endl;
            }
        }
    }
    return 0;
}