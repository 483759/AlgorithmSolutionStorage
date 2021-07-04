#include <cstdio>
#include <vector>
using namespace std;
int n, m;
bool v[2001],ans;
vector<int> edge[2001];
bool dfs(int pre, int dep) {
	if (dep >= 5)
		return true;
	for (auto x: edge[pre]) {
		if (v[x])continue;
		v[x] = 1;
		if (dfs(x, dep + 1))
			return true;
		v[x] = 0;
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		v[i] = 1;
		if (dfs(i, 1))
			ans = true;
		v[i] = 0;
	}
	printf("%d", ans ? 1 : 0);
	return 0;
}