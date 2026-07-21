#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v;
	int w;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	if (!(cin >> n)) return 0;
	vector<Edge> edges;// 存储所有的边长信息
	edges.reserve(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		int w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});//存储完整的边长相关信息
	}

	long long ans = 0;
	const long long NEG = (long long)-4e18;

	// 对每一位独立处理
	for (int b = 0; b < 30; ++b) {
		vector<char> forced1(n + 1, 0), forced0(n + 1, 0);
		vector<vector<int>> zeroAdj(n + 1);

		// 建“0-边”邻接，同时标出强制为1的点
		for (const auto &e : edges) {
			if ((e.w >> b) & 1) {
				forced1[e.u] = 1;
				forced1[e.v] = 1;
			} else {
				zeroAdj[e.u].push_back(e.v);
				zeroAdj[e.v].push_back(e.u);
			}
		}

		// 强制0：与强制1通过“0-边”相邻的点必须为0
		for (int u = 1; u <= n; ++u) if (forced1[u]) {
			for (int v : zeroAdj[u]) {
				forced0[v] = 1;
			}
		}

        // 以上的情况就是在现有条件下情况中的固定值为0和1的部分

		long long countForced1 = 0;
		for (int u = 1; u <= n; ++u) if (forced1[u]) ++countForced1;// 计算固定为1的数量

		// 在仅包含“0-边”的森林上做树形DP（跳过强制1的点）
		vector<char> vis(n + 1, 0); //  是否已经访问过
		vector<long long> dp0(n + 1, 0), dp1(n + 1, 0);// dp0[u],dp1[u]表示的是在当前的数据为0或者为1的时候，子节点有多少可以取得1
		long long addFree = 0;

        //由于我们剩下的部分大概率不是一棵树，而是一片树林
        //所以说我们这边的解决方法是，遍历所有的开始节点进行处理。
		for (int s = 1; s <= n; ++s) {// 这里是处理所有选择
			if (forced1[s] || vis[s]) continue;//如果是确定值为1或者说是已经讨论过的就跳过

			// 迭代DFS（两阶段：入栈/出栈）以避免递归
			struct Item { int u, p, st; };//u 当前节点，p 父节点，st状态;
			vector<Item> st;
			st.reserve(64);
			st.push_back({s, 0, 0});
			vis[s] = 1;

            //在一个栈中间进行计算
			while (!st.empty()) {
				auto cur = st.back();
				st.pop_back();
				int u = cur.u, p = cur.p, state = cur.st;

				if (state == 0) {
					// 进入：稍后回溯计算，先压出栈标记
					st.push_back({u, p, 1});//这个时候就把state转化成1输入回去了。
					for (int v : zeroAdj[u]) {//zeroAdj就是以0为边创建的邻接表
						if (v == p || forced1[v] || vis[v]) continue;//p是已经讨论过的；vis表示不容在同一个连通分量进行讨论
						vis[v] = 1;
						st.push_back({v, u, 0});//插入的state是0.说明我们第一步是将所有边关系（原来其实是存储在zeroAdj中间的部分）转移到state中；
                        //当state为0的时候我就是把这部分关系输入到了栈中
                        //由于我们使用的是栈结构，所以说我们要到所有的state=0的情况都处理之后，才会开始处理state=1 的部分
					}
				} else {
					// 回溯：计算dp
					long long take0 = 0;
					long long take1 = forced0[u] ? NEG : 1;//如果说take1强制为0则将其赋值一个无限小的数据，如果不是则赋予
					for (int v : zeroAdj[u]) {
						if (v == p || forced1[v]) continue;// v == p 跳过父节点

						// 由于 v 已经在其他的回溯阶段计算好
						long long c0 = dp0[v], c1 = dp1[v];// dp0[u],dp1[u]表示的是在当前的数据为0或者为1的时候，子节点有多少可以取得1
						take0 += max(c0, c1);// 如果我们选择0，此时最优解就是剩下两种选择大的那一个
						if (take1 > NEG / 2) take1 += c0; // 若u=1，孩子必须取0
					}
					dp0[u] = take0;
					dp1[u] = take1;

					// 若是该连通分量根，累计贡献
					if (p == 0) {//p=0 其实就是最终的情况，说明是此时已经是有解了。
						addFree += max(dp0[u], dp1[u]);
					}
				}
			}
		}

		long long ones = countForced1 + addFree;// 
		ans += ones * (1LL << b);
	}

	cout << ans << '\n';
	return 0;
}
