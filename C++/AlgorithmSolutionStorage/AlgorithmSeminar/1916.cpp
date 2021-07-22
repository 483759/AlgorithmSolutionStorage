#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

vector<vector<pii>> g;
int n, m,s,f;

int dijkstra() {
	vector<int> dist(n+1,INF);
	priority_queue<pii> pq;

	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first > dist[cur.second])continue;

		for (auto x : g[cur.second]) 
		if(dist[x.second]>x.first+dist[cur.second]){
			dist[x.second] = x.first + dist[cur.second];
			pq.push(make_pair(dist[x.second], x.second));
		}
	}
	return dist[f];
}

int main() {
	scanf("%d%d", &n, &m);
	g = vector<vector<pii>>(n + 1);

	for (int i = 0,u,v,w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
	}
	scanf("%d%d", &s, &f);
	printf("%d", dijkstra());
	return 0;
}