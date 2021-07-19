#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int dijkstra(int a, int b,vector<vector<int>> graph) {
	vector<int> dist(graph.size(),INF);
	vector<bool> visit(graph.size(), false);
	priority_queue<pii, vector<pii>> pq;

	dist[a] = 0;
	pq.push(make_pair(0, a));

	while (!pq.empty()) {
		int cost = pq.top().first * -1;
		int cur = pq.top().second;
		pq.pop();

		visit[cur] = true;
		for (int x : graph[cur]) {
			if (!visit[x] && dist[x] > cost + 1) {
				dist[x] = cost + 1;
				pq.push(make_pair(-dist[x], x));
			}
		}
	}
	return dist[b] == INF ? -1 : dist[b];
}

int main() {
	int a, b, n, m;
	scanf("%d%d%d%d", &a, &b, &n, &m);

	vector<vector<int>> graph(n+1);
	for (int i = 0,u,v; i < m; i++) {
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	printf("%d", dijkstra(a, b, graph));
	return 0;
}