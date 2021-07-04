#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 100005
using namespace std;
int v, e, id, tc, pre[MAX], snum[MAX], total = 1, in[MAX];
bool visit[MAX];
vector<int> adj[MAX];
vector<vector<int>> scc;
stack<int> s;
int dfs(int cur) {
	pre[cur] = ++id;
	s.push(cur);

	int parent = pre[cur];
	for (auto x : adj[cur]) {
		if (!pre[x])parent = min(parent, dfs(x));
		else if (!visit[x])parent = min(parent, pre[x]);
	}

	if (parent == pre[cur]) {
		vector<int> SCC;
		while (1) {
			int k = s.top(); s.pop();
			SCC.push_back(k);
			visit[k] = 1;
			snum[k] = total;
			if (k == cur)break;
		}
		scc.push_back(SCC);
		total++;
	}
	return parent;
}
int main() {
	int ans = 0; id = 0; total = 1;
	scanf("%d%d", &v, &e);
	for (int i = 0, U, V; i < e; i++) {
		scanf("%d%d", &U, &V);
		adj[U].push_back(V);
	}
	for (int i = 0; i < v; i++)
		if (!pre[i])dfs(i);
	sort(scc.begin(), scc.end());
	for (int i = 0; i < v; i++) {
		for (auto x : adj[i])
			if (snum[i] != snum[x])
				in[snum[x]]++;
		adj[i].clear();
	}
	for (int i = 1; i < total; i++) {
		if (!in[i])ans++;
		in[i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <stack>
//using namespace std;
//
//vector<vector<int>> G,R;
//vector<int> scc;
//vector<bool> visit;
//stack<int> s;
//int n, m,k;
//
//void dfs(int cur) {
//	visit[cur] = 1;
//	for (auto x : R[cur])
//		if (!visit[x])dfs(x);
//	s.push(cur);
//}
//
//void dfs2(int num, int cur) {
//	visit[cur] = 1;
//	scc[cur] = num;
//	for (auto x : G[cur])
//		if (!visit[x])dfs2(num, x);
//}
//
//int main() {
//	scanf("%d%d", &n, &m);
//	G.resize(n); R.resize(n); scc.resize(n);
//	visit = vector<bool>(n,false);
//
//	for (int i = 0,u,v; i < m; i++) {
//		scanf("%d%d", &u, &v);
//		G[u].push_back(v);
//		R[v].push_back(u);
//	}
//
//	for (int i = 0; i < n; i++)
//		if (!visit[i])dfs(i);
//	visit = vector<bool>(n, false);
//
//	while (!s.empty()) {
//		int cur = s.top(); s.pop();
//		if (visit[cur])continue;
//		dfs2(++k, cur);
//	}
//	printf("%d", k);
//	
//	return 0;
//}