#include <cstdio>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int n, e,x, ans;
vector<pair<int, int>> edge[1005];
int dijkstra(int u, int v) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,u });
	dist[u] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second; pq.pop();

		for (auto x : edge[cur]) {
			if (dist[cur] + x.second < dist[x.first]) {
				dist[x.first] = dist[cur] + x.second;
				pq.push({ -dist[x.first],x.first });
			}
		}
	}
	return dist[v];
}
int main() {
	scanf("%d%d%d", &n, &e,&x);
	for (int i = 0, a, b, c; i < e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		edge[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
		int k = dijkstra(i, x)+dijkstra(x,i);
		if (k > ans)ans = k;
	}
	printf("%d", ans);
	return 0;
}