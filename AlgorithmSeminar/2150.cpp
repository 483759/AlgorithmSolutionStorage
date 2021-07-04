#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
vector<int> d[100005], r[100005];
stack<int> s;
bool visit[100005];
int n, m,ans,tc;
void dfs(int cur) {
	visit[cur] = 1;
	for (auto x : r[cur])
		if (!visit[x])dfs(x);
	s.push(cur);
}
void dfs2(int cur) {
	visit[cur] = 1;
	for (auto x : d[cur])
		if (!visit[x])dfs2(x);
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0, u, v; i < m; i++) {
			scanf("%d%d", &u, &v);
			d[u].push_back(v);
			r[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				dfs(i);
		memset(visit, 0, sizeof(visit));
		while (!s.empty()) {
			int k = s.top(); s.pop();
			if (visit[k])continue;
			dfs2(k); ans++;
		}
		printf("%d\n", ans);
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			d[i].clear();
			r[i].clear();
		}
	}
	return 0;
}