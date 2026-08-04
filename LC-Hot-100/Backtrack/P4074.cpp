#include<bits/stdc++.h>
using namespace std;
bool str_check(string s){
    int left = 0;
    int right = s.size() - 1;
    int mid=(left + right) / 2;
    bool flag = true;
    for (int i = 0;i<=mid;i++){
        if(s[left+i]!=s[right-i]){
            flag=false;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}

bool vec_check(vector<bool>&board,string str){
    vector<string> checkList;
    string s = "";
    for (int i = 0; i < board.size();i++){
        s += str[i];
        if(i== board.size()-1){
            checkList.push_back(s);
            break;
        }
        if(board[i]){
            checkList.push_back(s);
            s = "";
        }
    }

    bool flag = true;
    for(string s:checkList){
        if(!str_check(s)){
            flag = false;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
    

}

void dfs(int index,string str,vector<bool>&board,vector<vector<bool>>& res){
    if(index==str.size()-1){//board最后一个数据其实是无效的，我是在vec判断的时候才使用了这个值
        //对于最后一个值取true和false，正好会使得解答的数量翻倍。
        if(vec_check(board,str)){
            res.push_back(board);
        }
        return;
    }

    board[index] = true;
    dfs(index + 1, str, board, res);
    board[index]=false;
    dfs(index + 1, str, board, res);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;
    int n = str.size();
    if(n==1){
        cout << str;
        return 0;
    }
    vector<bool> board(n ,false);//选择策略
    vector<vector<bool>> res;

    dfs(0, str, board, res);

    for(auto boards:res){
        vector<string> ans;
        string s = "";
        for (int i = 0; i < boards.size();i++){
            s += str[i];
            if(i== boards.size()-1){
                ans.push_back(s);
                break;
            }
            if(boards[i]){
                ans.push_back(s);
                s = "";
            }
        }
        for(string s:ans){
            cout << s << " ";
        }
        cout << endl;
    }

    
    
    /*
    string str;
    cin >> str;
    if(str_check(str))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    */
   

    return 0;
}
/*
- 本题中其实最大的问题是要想到这个分割的思路。这里的思路是使用board进行分割，这样分割之后就能够对于所有的情况进行判断

- 但是本题也有优化空间，实际上应该是对于所有的index都使用进行分别讨论而不是所有的放在一起讨论。
- 这样就不是我们先确定我们的分割策略之后再来分析正确性，相对来说更加优秀

*/