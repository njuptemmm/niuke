#include<string>
#include<iostream>
using namespace std;
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    size_t length1 = s1.length();
    size_t length2 = s2.length();
    int num = length2 % length1;
    if(num!=0){
        cout << "No" << endl;
        return 0;
    }
    else{
        int a = length2 / length1;
        string s3="";
        while(a--){
            s3 += s1;
        }
        if(s3==s2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}