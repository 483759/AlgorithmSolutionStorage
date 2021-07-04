#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
int n, T, arr[21][21], dx[] = { 1, -1, 1, -1 }, dy[] = {1, 1, -1, -1};
bool visit[21][21];
typedef struct {
	int x, y;
}point;
queue<point> q;
bool safe(int x, int y) {
	if (!(x || y) || x * y == n * n)return false;
	return x >= 0 && x < n && y >= 0 && y < n;
}
int bfs(point p) {
	visit[p.y][p.x] = true;
	q.push({ p.x,p.y });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int next = 0; next < 4; next++)
			if (safe( && !visit[next]) {
				visit[next] = true;
				q.push(next);
			}
	}
}int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)scanf("%d", &arr[i][j]);


	}
	return 0;
}