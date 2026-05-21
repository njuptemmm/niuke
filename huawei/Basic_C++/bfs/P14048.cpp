#include<bits/stdc++.h>
using namespace std;

const int n = 1e6; // b的最大值是1e6;
int a, b;

int type2(int a){
    int p1=a%10;
    int p2 = a / 10;
    //计算位数
    int num = p2;
    int wei = 0;
    while(num>0){
        num/=10;
        wei++;
    }
    int ans=p1*pow(10,wei)+p2;
    return ans;
}

void bfs(vector<int>& value){
    queue<int> q;
    q.push(1);
    value[1] = 0;
    while(q.size()!=0){
        int node=q.front();
        q.pop();
        int t1 = node * a;
        int t2=type2(node);
        if(t1>0&&t1<n&&value[t1]==-1){
            q.push(t1);
            value[t1] = value[node] + 1;
        }
        if(t2>0&&t2<n&&value[t2]==-1){
            q.push(t2);
            value[t2] = value[node] + 1;
        }
    }
    return;
}

int main(){
    cin >> a >> b;
    vector<int>value(n,-1);//用来存储相关值
    bfs(value);
    cout << value[b] << endl;

    return 0;
}
/*
- type1:原有数值*a；
- type2：119-》911
//start：1 end:b
*/