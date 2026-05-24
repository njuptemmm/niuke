#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> numbers;
    numbers.push_back(0);
    int max = 0;
    for (int i = 0; i < n;i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    int q;
    cin >> q;
    vector<int> xu;
    for (int j = 0; j < q;j++)
    {
        int l, r;
        cin >> l>> r;
        int max = 0;
        for (int i = l; i <= r;i++){
            int num = numbers.at(i);
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
        cout << endl;
        xu.clear();
    }
    return 0;
}