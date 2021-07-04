#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> indeg,sem;
vector<vector<int>> g;

int main() {
	scanf("%d%d", &n, &m);
	indeg = vector<int>(n + 1,0);
	sem = vector<int>(n + 1,1001);
	g = vector<vector<int>>(n + 1);

	for (int i = 0,a,b; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		indeg[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!indeg[i]) {
			q.push(i);
			sem[i] = 1;
		}

	while (!q.empty()) {



















	}
	return 0;
}