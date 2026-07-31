#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;

    int x = 0;
    int y=n-1;
    bool flag = false;
    while(x<m&&y>=0){
        int num=arr[x][y];
        if(num==target){
            flag = true;
            break;
        }
        else if(num<target){
            x++;
        }
        else
            y--;
    }

    if(flag) cout<<"true";
    else
        cout << "false";
    return 0;
}

/*
- 不能使用hash，因为后面数据上去之后输入的数据太多hash table存储不过来
- 解题方法是使用特殊遍历。主要的遍历方法是
    - 从最右上和最左下的部分开始遍历。
    - 这样移动的时候可以做到经历的每一个点，其向下一定是增大，向左一定是接下
    - 不会出现常规遍历的时候两个方向都是增加/缩小

- 除了上面的思路问题还有一个比较重要的内容是其中我们使用的m和n边界条件出现问题
*/