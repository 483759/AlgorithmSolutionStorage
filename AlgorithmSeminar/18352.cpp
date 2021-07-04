#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<vector<int>> g;
int n, m, k, X;

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &X);
	g = vector<vector<int>>(n + 1);

	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
	}

	vector<int> dist(n + 1, INF);
	vector<bool> visit(n + 1, false);
	priority_queue<pair<int, int>> pq;
	dist[X] = 0;
	pq.push(make_pair(0, X));

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop(); cur.first *= -1;
		if (visit[cur.second])continue;

		visit[cur.second] = true;
		for (auto x : g[cur.second]) {
			if (dist[x] > cur.first + 1) {
				dist[x] = cur.first + 1;
				pq.push(make_pair(-dist[x], x));
			}
		}
	}

	bool b = 1;
	for (int i = 1; i <= n; i++)
		if (dist[i] == k) {
			printf("%d\n", i); b = 0;
		}
	if (b)printf("-1");
	return 0;
}