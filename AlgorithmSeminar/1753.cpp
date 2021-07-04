#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int V,e,k,dist[20005];
vector<pair<int, int>> g[20005];
void dijkstra(int u) {
	priority_queue<pair<int, int>> pq;
	fill(&dist[0], &dist[V+1], INF);
	pq.push({ 0,u });
	dist[u] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;

			if (dist[cur] + ncost < dist[next]) {
				dist[next] = dist[cur] + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &V, &e,&k);
	for (int i = 0; i < e; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v, w));
	}dijkstra(k);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}