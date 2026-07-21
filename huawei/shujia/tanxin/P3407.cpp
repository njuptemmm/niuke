#include<bits/stdc++.h>
using namespace std;

const long long NEG = -4e18;

struct EDGE{
    int u, v, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<EDGE>edges;//用来存储所有的边的信息
    for (int i = 0; i < n-1;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    long long ans = 0;

    for (int b = 0; b < 30;b++){
        // rule中固定的值
        vector<int> force1(n + 1, 0);
        vector<int> force0(n + 1, 0);

        // 0部分的无向图
        vector<vector<int>> zeroAdj(n+1);//这里是使用的动态的方式，让后面使用pushback进行添加减少使用空间。
        //vector<EDGE> edges0;

        //将edges边相关的信息添加到force中
        for(auto e:edges){
            if((e.w >> b) & 1){//将1左移b位之后可以得出第b位数字的值
                force1[e.u] = 1;
                force1[e.v] = 1;
            } 
            else{
                zeroAdj[e.u].push_back(e.v);
                zeroAdj[e.v].push_back(e.u);
                //edges0.push_back(e);//将当前位置中值为0部分的只进行存储
            }
        }

        //由于rules我们可以确定其中值为0 的部分 
        for (int u = 1;u<=n;u++){
            if(force1[u]==1){
                for(int v:zeroAdj[u]){//处理所有收到影响的点
                    force0[v] = 1;
                }
            }
        }

        // 在最开始的时候我们可以确认的值
        long long countForce1 = 0;
        for(int u = 1; u <= n;u++){
            if(force1[u])
                countForce1++;
        }
        long long addfree=0;

        struct ITEM{
            int u, p, st;
        };
        vector<int> vis(n + 1, 0);// 由于我们讨论的是无向图，会出现很多的树林，使用vis保证都访问到/不会重复访问
        vector<long long> dp0(n + 1, 0);// dp1[u] u=1时候解的数量
        vector<long long> dp1(n + 1, 0);

        // 对于其中数据，处理所有的树林
        for (int s = 1; s <= n; s++)
        {

            if(vis[s]||force1[s])
                continue;
            
            stack<ITEM> st;
            st.push({s, 0, 0});//其中分别表示的是当前状态、父节点、标记使用st；
            vis[s] = 1;

            while(!st.empty()){//当前的栈不为空的时候
                auto cur=st.top();
                st.pop();
                int u = cur.u;
                int p = cur.p;
                int state = cur.st;

                if(state==0){
                    st.push({u, p, 1});//将相关的值重新输入到st中间
                    for(int v:zeroAdj[u]){
                        if(v==p||force1[v]||vis[v]) continue;
                        else{
                            vis[v] = 1;
                            st.push({v, u, 0});//将相关的数值推进去重新进行计算
                        }
                    }
                }
                else{//此时state==1，开始计算最优解
                    long long token0 = 0;
                    long long token1 = force0[u] ? NEG : 1;
                    for(int v:zeroAdj[u]){//讨论和u连接的所有情况，也就是所有v的情况
                        if(v==p||force1[v]) continue;
                        else{
                            //将相关的值和v中间出现的值进行递加
                            long long c0 = dp0[v];
                            long long c1 = dp1[v];
                            token0+=max(c0,c1);
                            if(token1>NEG/2)
                                token1 += c0;
                        }
                        dp0[u] = token0;
                        dp1[u] = token1; 

                        if(p==0){
                            addfree += max(dp0[u], dp1[u]);
                        }
                    }
                }
            }
            
        }

        long long sum = addfree + countForce1;
        ans += sum * (1LL << b);
    }
    cout << ans << endl;
    return 0;
}
/*
- rules:
    - w=1,两边的值都为1
    - w=0，两边的值仅有一个为1并且另一个为0，或者两个都是0
    - max_val:指代的是：当我们所有的每一位中都是取出现x次数最多的时候，就可以确认值的结果是怎样的。
*/