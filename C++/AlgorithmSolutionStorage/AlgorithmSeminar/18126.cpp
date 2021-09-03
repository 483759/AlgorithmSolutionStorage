#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ull unsigned long long
using namespace std;

int n;
vector<vector<pii>> g;
vector<bool> visit;

ull dfs(int cur) {
	visit[cur] = true;

	ull dist = 0;
	for (auto x : g[cur]) {
		if (visit[x.first])continue;
		ull k = dfs(x.first) + x.second;
		dist = max(dist, k);
	}
	return dist;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	g = vector<vector<pii>>(n + 1);
	visit = vector<bool>(n + 1, false);

	for (int i = 0, u, v, w; i < n - 1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	printf("%lld", dfs(1));
	return 0;
}