#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
bool graph[1001][1001];
bool visit[1001];
stack<int> s;
queue<int> q;
int N, M;
void bfs(int node) {
	visit[node] = true;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int next = 1; next <= N; next++)
			if (!visit[next] && graph[cur][next]) {
				visit[next] = true;
				q.push(next);
			}
	}
	printf("\n");
}
void dfs(int node) {
	s.push(node);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (visit[cur])continue;
		visit[cur] = true;
		printf("%d ", cur);
		for (int next = N; next >= 1;next--)
			if (!visit[next] && graph[cur][next])
				s.push(next);
	}
	printf("\n");
}
int main() {
	int v;
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &v);
	for (int i = 0, from, to; i < M; i++) {
		scanf("%d%d", &from, &to);
		graph[from][to] = true;
		graph[to][from] = true;
	}

	dfs(v);
	for (int i = 0; i < 1001; i++)
		visit[i] = false;
	bfs(v);
}