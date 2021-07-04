#include <cstdio>
#include <vector>
#include <algorithm>
#define INF -987654321
using namespace std;

typedef struct { int u, v, w; }edge;
vector<edge> e;
int n, m, graph[105][105], city[105], pre[105], s, f;
long long dist[105];
bool visit[105];

bool dfs(int cur) {
	if (cur == f)return true;
	visit[cur] = true;
	bool chk = false;
	for (auto x : e) {
		if (x.u == cur && !visit[x.v])
			chk |= dfs(x.v);
	}
	return chk;
}

int main() {
	scanf("%d%d%d%d", &n, &s, &f, &m);
	fill(&dist[0], &dist[n + 1], INF);

	for (int i = 0, u, v, w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e.push_back({ u,v,w });
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &city[i]);
	}

	dist[s] = city[s];
	pre[s] = -1;
	for (int k = 0; k < n-1; k++)
		for (auto x : e) {
			if (dist[x.u] != INF && (dist[x.v] < dist[x.u] - x.w + city[x.v]))
				dist[x.v] = dist[x.u] - x.w + city[x.v];
		}

	if (dist[f] == INF)printf("gg");
	else {

		for (auto x : e) {
			if (dist[x.u] != INF && (dist[x.v] < dist[x.u] - x.w + city[x.v]))
				if (dfs(x.u)) {
					printf("Gee");
					return 0;
				}
		}
		printf("%lld", dist[f]);
	}
	return 0;
}