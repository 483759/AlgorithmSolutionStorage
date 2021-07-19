#include <cstdio>
#include <queue>
using namespace std;
bool visit[100];
int N, graph[100][100];
queue<int> q;
void bfs(int node) {
	visit[node] = true;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for(int next = 0;next<N;next++)
			if (graph[cur][next] && !visit[next]) {
				visit[next] = true;
				q.push(next);
			}
	}
}
void dfs(int cur) {
	visit[cur] = true;
	for (int next = 0; next < N; next++)
		if (!visit[next] && graph[cur][next])
			dfs(next);
}