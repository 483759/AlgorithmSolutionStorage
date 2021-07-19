#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int v, e, p;
vector<vector<pii>> g;

int dijkstra(int source, int sink) {
	vector<int> dist(g.size(),INF);
	vector<bool> visit(g.size(), false);
	priority_queue<pii> pq;

	pq.push(make_pair(0, source));
	dist[source] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (visit[cur])continue;

		visit[cur] = true;
		for (auto x : g[cur]) 
		if(!visit[x.second]&&(dist[x.second]>dist[cur]+x.first)){
			dist[x.second] = dist[cur] + x.first;
			pq.push(make_pair(-dist[x.second], x.second));
		}
	}

	return dist[sink];
}

int main() {
	scanf("%d%d%d", &v, &e, &p);
	g = vector<vector<pii>>(v + 1);

	for (int i = 0,u,v,w; i < e; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	if ((dijkstra(1, p) + dijkstra(p, v)) <= dijkstra(1, v))printf("SAVE HIM");
	else printf("GOOD BYE");
	return 0;
}