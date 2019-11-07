#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
int n;
bool g[101][101], visit[101];
queue<int> q;
bool bfs(int node, int d) {
	visit[node] = true;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for(int i=0;i<n;i++)
			if (g[cur][i] && (!visit[i]||i==node)) {
				visit[i] = true;
				q.push(i);
				if (i == d) return true;
			}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &g[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", bfs(i, j));
			memset(visit, false, sizeof(visit));
			while (!q.empty())q.pop();
		}
		printf("\n");
	}
	return 0;
}