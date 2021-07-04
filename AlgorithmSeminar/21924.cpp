#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

vector<vector<pii>> g;
int n, m, sum;

long long prim() {
	priority_queue<pii> pq;
	vector<int> cost(n + 2, INF);
	vector<bool> visit(n + 2, false);

	long long ans = 0;
	pq.push(make_pair(0, 1));
	cost[1] = 0;

	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visit[cur.second])continue;

		visit[cur.second] = 1;
		for (auto x : g[cur.second])
			if ((cost[x.second] > x.first) && !visit[x.second]) {
				cost[x.second] = x.first;
				pq.push(make_pair(-cost[x.second], x.second));
			}
	}

	for (int i = 1; i <= n; i++) {
		if (cost[i] == INF)return -1;
		ans += cost[i];
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	g = vector<vector<pii>>(n + 1);
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(make_pair(c, b));
		g[b].push_back(make_pair(c, a));
		sum += c;
	}
	long long ans = prim();
	printf("%lld", ans == -1 ? -1 : sum - ans);
	return 0;
}