#include<iostream>
#include<unordered_map>
#include<sstream>
#include<string>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    
    unordered_map<int, int> arr;
    
    while(n--){
        int num;
        cin >> num;
        arr[num]++;
    }

    while(q--){
        int num;
        cin >> num;
        if(arr.find(num)==arr.end()){
            cout << 0 << endl;
        }
        else{
            cout << arr.at(num) << endl;
        }
    }
    return 0;
}