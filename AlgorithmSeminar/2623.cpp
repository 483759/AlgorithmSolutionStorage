#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indeg,ans;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	g = vector<vector<int>>(n + 1);
	indeg = vector<int>(n + 1, 0);

	for (int i = 0,k; i < m; i++) {
		scanf("%d", &k);
		int pre, post;
		scanf("%d", &pre);
		for (int j = 0; j < k - 1; j++) {
			scanf("%d", &post);
			g[pre].push_back(post);
			indeg[post]++;
			pre = post;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!indeg[i])q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);

		for (auto x : g[cur]) {
			if (!indeg[x])continue;

			if (--indeg[x] == 0) {
				q.push(x);
			}
		}

	}

	if (ans.size() != n)printf("0");
	else {
		for (auto x : ans)
			printf("%d\n", x);
	}

	return 0;
}