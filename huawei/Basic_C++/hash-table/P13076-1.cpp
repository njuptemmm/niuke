#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int count = 0;
    unordered_map<int, int> pair;
    for (int i = 0; i < n;i++){
        int temp = (i+1)-arr[i];
        if(pair.find(-temp)!=pair.end()){
            count += pair[-temp];
        }
        pair[temp]++;
    }
    cout<<count<<endl;
    return 0;
}