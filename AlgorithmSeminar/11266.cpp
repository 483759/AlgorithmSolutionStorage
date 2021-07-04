#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int V, E, cnt, pre[10005], low[10005];
vector<int> graph[10005], cutVertex;
bool visit[10005];

void dfs(int v, int p) {
	visit[v] = true;
	pre[v] = low[v] = ++cnt;
	int children = 0, isCutVertex = 0;

	for (auto u : graph[v]) {
		if (u == p)continue;
		if (visit[u]) {
			low[v] = min(low[v], pre[u]);
		}
		else {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (p && low[u] >= pre[v])
				isCutVertex = 1;
			++children;
		}
	}
	if (p == 0 && children > 1)
		isCutVertex = 1;
	if (isCutVertex)
		cutVertex.push_back(v);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &V, &E);

	for (int i = 0, u, v; i < E; i++) {
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if (!visit[i])
			dfs(i, 0);
	}

	sort(cutVertex.begin(), cutVertex.end());

	printf("%d\n", cutVertex.size());
	for (int v : cutVertex)
		printf("%d ", v);
	return 0;
}