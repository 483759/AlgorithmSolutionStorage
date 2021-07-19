#include <cstdio>
#define t 1000000007
#define ull unsigned long long
ull n;
ull fibo(ull k) {
	if (!k)return 0;
	if (k == 1)return 1;
	return (fibo(k-1)%t)+
}
int main() {
	scanf("%lld", &n);
	return 0;
}
//#include <cstdio>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define INF 987654321
//using namespace std;
//int n, m;
//vector<pair<int, int>> edge[1001];
//int dijkstra(int u, int v) {
//	int dist[1005];
//	priority_queue<pair<int, int>> pq;
//	fill(&dist[0], &dist[n + 1], INF);
//	pq.push({ 0,u });
//	dist[u] = 0;
//
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//		
//		for (int i = 0; i < edge[cur].size(); i++) {
//			int next = edge[cur][i].first;
//			int ncost = edge[cur][i].second;
//
//			if (dist[cur] + ncost < dist[next]) {
//				dist[next] = dist[cur] + ncost;
//				pq.push({ -dist[next],next });
//			}
//		}
//	}
//	return dist[v];
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < m; i++) {
//		int u, v, w;
//		scanf("%d%d%d", &u, &v, &w);
//		edge[u].push_back(make_pair(v, w));
//	}int u, v;
//	scanf("%d%d", &u, &v);
//	printf("%d", dijkstra(u,v));
//	return 0;
//}