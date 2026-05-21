#include<bits/stdc++.h>
using namespace std;

struct node{
    int root;
    string name;
    vector<string> phones;
};

vector<int> parent;

//用来寻找编号对应的父节点
int find(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int xroot=find(x);
    int yroot=find(y);
    if(xroot!=yroot){
        parent[xroot] = yroot;//合并到同一个数据中
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string str;
    getline(cin, str);
    vector<node> arr(n + 1);
    parent.resize(n + 1);

    //初始化并查集中根节点目录
    for (int i = 1; i <= n;i++){
        parent[i] = i;
    }

    // 使用遍历的方法将数据不断输入，将相关的信息存储在arr中间
    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string str1;
        bool flag = true;
        // 初始化所有的root；
        arr[i].root = i;

        while (ss >> str1)
        {
            if (flag)
            {
                flag = false;
                arr[i].name = str1;
                continue;
            }
            arr[i].phones.push_back(str1);
        }
    }

    //使用O(n^2)复杂度的直接遍历完成
    //使用遍历的方法遍历所有的电话号码，进行匹配
        for (int i = 1; i <= n;i++){
            for (int j = i + 1;j<=n;j++){
                for (string str1:arr[i].phones){
                    bool flag = false;
                    for(string str2:arr[j].phones){
                        if(str1==str2){
                            merge(arr[i].root, arr[j].root);
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }

    vector<node> result;
    vector<int> visited(n + 1, -1);
    //用来判断当前的root节点中有没有被访问过
    for (int i = 1; i <= n;i++){
        int rt=find(arr[i].root);
        if(visited[rt]==-1){
            node nd;
            nd.root = rt;
            nd.name=arr[i].name;
            for(string s:arr[i].phones){
                nd.phones.push_back(s);//将所有的电话都输入之后再统一将电话输入到节点中
            }
            result.push_back(nd);
            visited[rt] = 1;
        }
        else{
            int idx = -1;
            for (int i = 0; i < result.size();i++){
                if(result[i].root==rt){
                    idx = i;
                    break;
                }
            }
            for(string s:arr[i].phones){
                result[idx].phones.push_back(s);
            }
        }
    }

    
    //这里出现问题：主要是visited数组和result数组对应的数据量不是一样的
    /*
    for (int i = 0; i < (int)result.size(); i++) {
        sort(result[i].phones.begin(), result[i].phones.end());
        for (int j = 1;j<result[i].phones.size();j++){
            if(result[i].phones[j-1]==result[i].phones[j])
                result[i].phones.erase(result[i].phones.begin() + (j - 1));//这里是使用去重的操作，这里是需要进行讨论一下的东西
        }
    }
    */
    
    
   //使用新的方法进行去重的操作
   
   for (int i = 0; i < (int)result.size(); i++){
        /*sort(result[i].phones.begin(), result[i].phones.end());
        auto last = unique(result[i].phones.begin(), result[i].phones.end());
        result[i].phones.erase(last, result[i].phones.end());*/
        sort(result[i].phones.begin(), result[i].phones.end());
        result[i].phones.erase(
        unique(result[i].phones.begin(), result[i].phones.end()),
        result[i].phones.end());
   }

   
    auto cmp = [](const node &x, const node &y) -> bool
    {
        if (x.name != y.name)
        {
            return x.name < y.name;
        }
        if (x.phones[0] != y.phones[0])
        {
            return x.phones[0] < y.phones[0];//用来比对result中间最小的部分
        }
        return false;
    };

    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < result.size();i++){
        cout<<result[i].name<<" ";
        for(string s:result[i].phones){
            cout << s << " ";
        }
        cout << '\n';
    }
    return 0;
}
/*


- 并查集相关整理
    - 首先就是要注意find()和merge()函数的形成func
    - 无论是什么形式，建议都是直接使用原始的形式，也就是使用func的方法从而实现
- stringstream的使用方法
    - 在对于string类型、无明确上限的题目进行解答的时候，使用stringstream同样可以过滤掉其中的空格
- 对于数组进行去重的思路
- 对于全局函数中，使用resize和reserve的区别是什么



*/