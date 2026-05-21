#include<bits/stdc++.h>
using namespace std;

struct node{
    int root;
    string name;
    vector<string> phones;
};

vector<int> parent;

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
        parent[xroot] = yroot;
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

    for (int i = 1; i <= n;i++){
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string str1;
        bool flag = true;
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
    for (int i = 1; i <= n;i++){
        int rt=find(arr[i].root);
        if(visited[rt]==-1){
            node nd;
            nd.root = rt;
            nd.name=arr[i].name;
            for(string s:arr[i].phones){
                nd.phones.push_back(s);
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

   for (int i = 0; i < (int)result.size(); i++){
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
            return x.phones[0] < y.phones[0];
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
