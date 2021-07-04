#include <cstdio>
#include <queue>
using namespace std;
int n, m,ans;
int map[105];
int visit[105];
queue<int> q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,u,v; i < n; i++) {
		scanf("%d%d", &u, &v);
		map[u] = v;
	}
	for (int i = 0, u, v; i < m; i++) {
		scanf("%d%d", &u, &v);
		map[u] = v;
	}

	visit[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == 100) {
			printf("%d", visit[cur]-1);
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int next = cur + i;

			if (next > 100)continue;
			if (map[next]) {
				if (visit[map[next]])continue;
				visit[map[next]] = visit[cur]+1;
				q.push(map[next]);
			}
			else {
				if (visit[next])continue;
				visit[next] = visit[cur]+1;
				q.push(next);
			}
		}
	}
	return 0;
}