#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
int n, m,cnt=1,indeg[32005];
priority_queue<int> pq;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n,&m);
	graph.assign(n+1, vector<int>());

	for (int i = 0, u, v; i < m; i++) {
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		indeg[v]++;
	}

	for (int i = 1; i <= n; i++)
		if (!indeg[i])pq.push(-i);

	while (!pq.empty()) {
		int cur = -pq.top(); pq.pop();

		printf("%d ", cur);
		for (int u : graph[cur]) {
			if (indeg[u]) {
				indeg[u]--;
				if (!indeg[u])pq.push(-u);
			}
		}

	}
	return 0;
}