#include <cstdio>
#include <queue>
using namespace std;
int m, n, ans, dx[] = { 0,1,1,1,0,-1,-1,-1 }, dy[] = { -1,-1,0,1,1,1,0,-1 };
bool map[251][251], visit[251][251];
struct point { int x, y; };
queue<point> q;
bool safe(int x, int y) {
	return x >= 0 && x < 250 && y >= 0 && y < 250;
}
void bfs(point p) {
	visit[p.y][p.x] = true;
	q.push(p);
	while (!q.empty()) {
		point c = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			point n = { c.x + dx[i], c.y + dy[i] };
			if (map[n.y][n.x] && !visit[n.y][n.x] && safe(n.x, n.y)) {
				visit[n.y][n.x] = true;
				q.push(n);
			}
		}
	}
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0, a = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			map[i][j] = a;
		}
	for (int i = 0, a = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] && !visit[i][j]) {
				bfs({ j,i });
				ans++;
			}
	printf("%d", ans);
	return 0;
}