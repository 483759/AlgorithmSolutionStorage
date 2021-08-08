#include <cstdio>
#include <vector>
#include <queue>
#define ull unsigned long long
#define pii pair<ull,int>
#define INF 1000000001
using namespace std;

int V, E, M;
vector<int> W(10);
vector<vector<pii>> g;
vector<vector<ull>> dist;

ull dijkstra(int S, int F) {
	if (!dist[S].empty())return dist[S][F];

	dist[S] = vector<ull>(V + 1, INF);
	priority_queue<pii, vector<pii>, greater<>> pq;

	dist[S][S] = 0;
	pq.push(make_pair(0, S));

	while (!pq.empty()) {
		int cur = pq.top().second; 
		int cost = pq.top().first; pq.pop();
		if (cost > dist[S][cur])continue;

		for (auto x : g[cur])
			if (dist[S][x.second] > x.first + dist[S][cur]) {
				dist[S][x.second] = x.first + dist[S][cur];
				pq.push(make_pair(dist[S][x.second], x.second));
			}
	}
	return dist[S][F];
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &V, &E);
	g = vector<vector<pii>>(V + 1);
	dist = vector<vector<ull>>(V + 1);

	for (int i = 0, u, v, w; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	for (int i = 0; i < 10; i++)scanf("%d", &W[i]);
	scanf("%d", &M);

	ull sum = 0;
	int cur = W[0], ans = V + 1;
	for (int i = 0; i < 10; i++) {
		ull d = dijkstra(cur, W[i]);
		if (d == INF)continue;

		sum += d;
		if (dijkstra(M, W[i]) <= sum) {
			ans = W[i] < ans ? W[i] : ans;
		}
		cur = W[i];
	}
	printf("%d", ans == V + 1 ? -1 : ans);
	return 0;
}