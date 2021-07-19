#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<vector<pair<int, int>>> graph;
int V, E;

int prim() {
	vector<int> cost(V + 1, INF);
	vector<int> prev(V + 1, -1);
	vector<bool> visit(V + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	
	pq.push(make_pair(0, 1));
	cost[1] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		visit[u] = true;
		for (auto next : graph[u]) {
			int v = next.second;
			int weight = next.first;

			if (!visit[v] && cost[v] > weight) {
				cost[v] = weight;
				pq.push(make_pair(cost[v], v));
				prev[v] = u;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= V; i++)
		sum += cost[i];
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &V, &E);
	graph.assign(V + 1, vector<pair<int, int>>());

	for (int i = 0, u, v, w; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	printf("%d", prim());
	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#define INF 987654321
//using namespace std;	
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//vector<vector<pair<int, int>>> edge;
//int v, e,cost[10005],pre[10005],ans;
//bool visit[10005];
//void prim(int u) {
//	visit[u] = true;
//	for (auto v : edge[u])
//		if (!visit[v.second])pq.push(v);
//
//	while (!pq.empty()) {
//		auto k = pq.top(); pq.pop();
//
//		if (!visit[k.second]) {
//			ans += k.first;
//			prim(k.second);
//			return;
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &v, &e); edge.resize(v + 1);
//	for (int i = 0,u,V,w; i < e; i++) {
//		scanf("%d%d%d", &u, &V, &w);
//		edge[u].push_back({ w,V });
//		edge[V].push_back({ w,u });
//	}
//	prim(1);
//	printf("%d", ans);
//	return 0;
//}