#include <queue>
#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N, Q;
vector<vector<pii>> g;

int main() {
	scanf("%d%d", &N, &Q);
	g = vector<vector<pii>>(N + 1);

	for (int i = 0,u,v,w; i < N - 1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	while (Q--) {
		int k, v, ans = 0;
		scanf("%d%d", &k, &v);

		queue<int> q;
		vector<bool> visit(N + 1, false);
		q.push(v);
		visit[v] = 1;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			ans++;

			for (auto x : g[cur]) {
				if (x.first >= k&&!visit[x.second]) {
					q.push(x.second);
					visit[x.second] = 1;
				}
			}
		}
		printf("%d\n", ans-1);

	}

	return 0;
}