#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef struct { int u, v, w; }edge;
int tc,n,m,w,dist[505];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		vector<edge> graph;
		scanf("%d%d%d", &n, &m, &w);
		
		for (int i = 0,s,e,t; i < m + w; i++) {
			scanf("%d%d%d", &s, &e, &t);
			if (i >= m)t *= -1;
			graph.push_back({ s,e,t });
			if (i < m) graph.push_back({ e,s,t });
		}
		fill(dist,dist+n+2, INF);

		bool flag = 0;
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (auto x : graph) {
				if (dist[x.u] + x.w < dist[x.v]) {
					dist[x.v] = dist[x.u] + x.w;
					if (i == n)flag = 1;
				}
			}
		}
		printf("%s\n", flag?"YES":"NO");
	}
	return 0;
}

//#include <cstdio>
//#include <vector>
//#define max 987654321
//using namespace std;
//int n, m, w, tc, s, e, t, weight[501];
//vector<vector<pair<int, int>>> v;
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	while (tc--) {
//		int flag = 0, size;
//
//		scanf("%d%d%d", &n, &m, &w);
//		v.clear();
//		v.resize(n + 1);
//
//		for (int i = 0; i < m; i++) {
//			scanf("%d%d%d", &s, &e, &t);
//			v[s].emplace_back(e, t);
//			v[e].emplace_back(s, t);
//		}
//		for (int i = 0; i < w; i++) {
//			scanf("%d%d%d", &s, &e, &t);
//			v[s].emplace_back(e, -t);
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)weight[j] = max;
//			weight[i] = 0;
//
//			for (int j = 1; j <= n; j++)
//				for (auto k : v[j]) {
//					if (weight[j] != max && (weight[j] + k.second < weight[k.first])) {
//						weight[k.first] = weight[j] + k.second;
//						if (i == n)flag = 1;
//					}
//				}
//		}
//		if (flag)printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}