#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int n, cost[101], k, scc[101], g[101][101], r[101][101];
bool visit[101];
stack<int> s;

void dfs(int cur) {
	visit[cur] = 1;
	for (int i = 0; i < n; i++)
		if (r[cur][i] && !visit[i])
			dfs(i);
	s.push(cur);
}

void dfs2(int k, int cur) {
	visit[cur] = 1;
	scc[cur] = k;
	for (int i = 0; i < n; i++)
		if (g[cur][i] && !visit[i])
			dfs2(k, i);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &cost[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%1d", &g[i][j]);
			r[j][i] = g[i][j];
		}

	for (int i = 0; i < n; i++)
		if (!visit[i])dfs(i);
	memset(visit, false, sizeof(visit));

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (!visit[cur])
			dfs2(++k, cur);
	}
	int ans = 0;
	for (int j = 1; j <= k; j++) {
		int min = 1000001;
		for (int i = 0; i < n; i++)
			if (scc[i] == j && cost[i] < min)
				min = cost[i];
		ans += min;
	}
	printf("%d", ans);
	return 0;
}