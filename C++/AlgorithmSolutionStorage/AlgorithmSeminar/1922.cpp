#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<vector<pair<int, int>>> edge;
int v, e, cost[10005], pre[10005], ans;
bool visit[10005];
void prim(int u) {
	visit[u] = true;
	for (auto v : edge[u])
		if (!visit[v.second])pq.push(v);

	while (!pq.empty()) {
		auto k = pq.top(); pq.pop();

		if (!visit[k.second]) {
			ans += k.first;
			prim(k.second);
			return;
		}
	}
}
int main() {
	scanf("%d%d", &v, &e); edge.resize(v + 1);
	for (int i = 0, u, V, w; i < e; i++) {
		scanf("%d%d%d", &u, &V, &w);
		edge[u].push_back({ w,V });
		edge[V].push_back({ w,u });
	}
	prim(1);
	printf("%d", ans);
	return 0;
}