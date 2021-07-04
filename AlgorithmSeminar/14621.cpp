#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n, m;
char mw[1001];
int graph[1005][1005];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> mw[i];
	fill(&graph[0][0], &graph[n + 2][n+1], INF);
	for (int i = 0, u, v, d; i < m; i++) {
		cin >> u >> v >> d;
		if (mw[u] == mw[v]||(graph[u][v] < d))continue;		
		graph[u][v] = graph[v][u]=d;
	}

	vector<int> cost(n + 1, INF);
	vector<int> prev(n + 1, -1);
	vector<bool> visit(n + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push(make_pair(0, 1));
	cost[1] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visit[u])continue;
		visit[u] = true;
		for (int v = 1; v <= n; v++) {
			if (graph[u][v] == INF)continue;

			int weight = graph[u][v];

			if (!visit[v] && cost[v] > weight) {
				cost[v] = weight;
				pq.push(make_pair(cost[v], v));
				prev[v] = u;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (cost[i] == INF) { printf("-1"); return 0; }
		sum += cost[i];
	}
	printf("%d", sum);
	return 0;
}