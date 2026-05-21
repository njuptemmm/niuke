#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int search(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        parent[x] = search(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int xroot=search(x);
    int yroot=search(y);
    if(xroot!=yroot){
        parent[xroot] = yroot;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(m+1);
        vector<int>b(m+1);
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        vector<vector<int>> map(n+1,vector<int>(n+1,-1));
        parent.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        //标记不相关的对子
        for (int i = 1; i <= m;i++){
            int n1=a[i];
            int n2=b[i];
            if(map[n1][n2]==-1){
                map[n1][n2]=1;
                map[n2][n1]=1;
            }
        }

        for (int i = 1; i <= m;i++){
            for (int j = 1; j <= m;j++){
                int n1=a[i];
                int n2=b[j];
                if(map[n1][n2]==-1){
                    merge(n1, n2);
                }
            }
        }

        bool flag = false;
        for (int i = 1; i <= m;i++){
            int n1=a[i];
            int n2=b[i];
            int aroot=search(n1);
            int broot=search(n2);
            if(aroot==broot){
                //cout << i << " " << j << '\n';
                flag = true;
                break;
            }
            if(flag)
                break;
        }

        if(!flag) cout<<"Yes"<<'\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}