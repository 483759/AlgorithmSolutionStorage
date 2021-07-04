#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 100005
using namespace std;
int v, e,id,tc, pre[MAX],snum[MAX],total=1,in[MAX];
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
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		int ans = 0; id = 0; total = 1;
		scanf("%d%d", &v, &e);
		for (int i = 0, U, V; i < e; i++) {
			scanf("%d%d", &U, &V);
			adj[U].push_back(V);
		}
		for (int i = 1; i <= v; i++)
			if (!pre[i])dfs(i);
		sort(scc.begin(), scc.end());
		for (int i = 1; i <= v; i++) {
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
		for (auto x : scc)
			x.clear();
		scc.clear();
		memset(pre, 0, sizeof(pre));
		memset(snum, 0, sizeof(snum));
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}