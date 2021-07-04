#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef struct { int u, v, w; }graph;
int n, m;
long long dist[505];
vector<graph> edge;

int main() {
	scanf("%d%d", &n, &m);
	edge = vector<graph>(m);
	fill(&dist[0], &dist[n + 2], INF);

	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		edge.push_back({ a,b,c });
	}

	dist[1] = 0;
	for (int k = 0; k < n - 1; k++) {
		for (auto x : edge) {
			if (dist[x.u] != INF && (dist[x.u] + x.w < dist[x.v]))
				dist[x.v] = dist[x.u] + x.w;
		}
	}

	for (auto x : edge) {
		if (dist[x.u] != INF && (dist[x.u] + x.w < dist[x.v]))
		{
			printf("-1");
			return 0;
		}
		
	}

	for (int i = 2; i <= n; i++)
		printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
	return 0;
}