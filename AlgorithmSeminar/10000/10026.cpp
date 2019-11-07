#include <cstdio>
#include <queue>
using namespace std;
int n, n1,n2, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char map[101][101];
bool visit[101][101];
struct point { int x, y; };
queue<point> q;
bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
void bfs(char c) {
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (map[ny][nx] == c && !visit[ny][nx] && safe(nx, ny)) {
				q.push({ nx, ny });
				visit[ny][nx] = true;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%s", map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				q.push({ j, i });
				bfs(map[i][j]);
				n1++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
			if (map[i][j] == 'G')map[i][j] = 'R';
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				q.push({ j, i });
				bfs(map[i][j]);
				n2++;
			}
		}
	}
	printf("%d %d", n1,n2);
	return 0;
}