#include <cstdio>
#include <queue>
using namespace std;
int s,t,val;
queue<int> q;
bool visit[10][10];
void bfs(int node) {
	q.push(node);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next = 0; next < 4; next++) {
			if (!next)val = cur + s;
			else if (next == 1)val = cur - s;
			else if (next == 2)val = cur * s;
			else val = cur / s;
			if (graph[cur][next] && !visit[]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d", &s, &t);
	return 0;
}