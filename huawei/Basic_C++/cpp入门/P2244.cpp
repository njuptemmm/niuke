#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){//getline：从标准输入中读取一整行数据
        stringstream ss(line);//stringstream 可以将line（字符串）转化成ss输入输出流
        long long num, sum = 0;
        //使用ss存储字符串的结果之后可以将其逐个进行输出的操作。
        while(ss>>num){
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}