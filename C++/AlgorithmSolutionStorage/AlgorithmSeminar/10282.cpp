#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

int tc, n, d, c;
vector<vector<pii>> g;

void dijkstra(int source) {
	int cost = 0,cnt=0;
	vector<int> dist(n, 987654321);
	vector<bool> visit(n, false);
	priority_queue<pii> pq;

	pq.push(make_pair(0, source));
	dist[source] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur])continue;
		visit[cur] = true; cnt++;

		for (auto x : g[cur]) {
			if (!visit[x.second]&&dist[x.second]>dist[cur]+x.first) {
				dist[x.second] = dist[cur] + x.first;
				pq.push(make_pair(-dist[x.second], x.second));
			}
		}
	}
	for (int i = 1; i < n; i++)
		cost = (dist[i]!= 987654321 &&dist[i] > cost) ? dist[i] : cost;
	printf("%d %d\n", cnt, cost);
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d", &n, &d, &c); n++;
		g = vector<vector<pii>>(n);
		for (int i = 0,u,v,w; i < d; i++) {
			scanf("%d%d%d", &u, &v, &w);
			g[v].push_back(make_pair(w, u));
		}
		dijkstra(c);
	}
	return 0;
}