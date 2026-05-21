#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 1; i <= n;i++){
        int yu = i % 10;
        int sum = 0;
        int num = i;
        while(num!=0){
            sum += num % 10;
            num = num / 10;
        }
        sum = sum % 10;
        if(yu==sum){
            numbers.push_back(i);
        }
    }
    cout << numbers.size() << endl;
    return 0;
}