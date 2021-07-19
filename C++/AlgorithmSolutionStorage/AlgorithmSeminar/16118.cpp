#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define pli pair<long long,int>
#define INF 10000000005
using namespace std;

vector<vector<pli>> g[2];
vector<ll> fox, wolf;
int n, m, ans;

void fox_dijkstra() {
	vector<bool> visit(n + 1, false);
	priority_queue<pli> pq;
	fox = vector<ll>(n + 1, INF);

	fox[1] = 0;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (visit[cur])continue;

		visit[cur] = true;
		for (auto x : g[0][cur])
			if (!visit[x.second] && (fox[x.second] > fox[cur] + x.first)) {
				fox[x.second] = fox[cur] + x.first;
				pq.push(make_pair(-fox[x.second], x.second));
			}
	}
}

void wolf_dijkstra() {
	priority_queue<pli, vector<pli>, greater<>> pq;
	wolf = vector<ll>(2 * n + 1, INF);

	wolf[1] = 0;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int cur = pq.top().second;
		ll cost = pq.top().first; pq.pop();
		if (cost > wolf[cur])continue;

		for (auto x : g[1][cur])
			if (wolf[x.second] > cost + x.first) {
				wolf[x.second] = cost + x.first;
				pq.push(make_pair(wolf[x.second], x.second));
			}
	}
}

// 2x - 1	-> slow vertex
// 2x		-> fast vertex
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	g[0] = vector<vector<pli>>(n + 1);
	g[1] = vector<vector<pli>>(2 * n + 1);

	for (int i = 0, a, b, d; i < m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		if (b > a) {
			int tmp = b; b = a; a = tmp;
		}
		g[0][a].push_back(make_pair(2 * d, b));
		g[0][b].push_back(make_pair(2 * d, a));

		g[1][2 * a - 1].push_back(make_pair(d * 4, 2 * b));
		g[1][2 * b].push_back(make_pair(d * 4, 2 * a - 1));

		g[1][2 * a].push_back(make_pair(d, 2 * b - 1));
		g[1][2 * b - 1].push_back(make_pair(d, 2 * a));
	}
	fox_dijkstra();
	wolf_dijkstra();

	for (int i = 1; i <= n; i++)
		if (fox[i] < min(wolf[2 * i - 1], wolf[2 * i]))
			ans++;
	printf("%d", ans);
	return 0;
}