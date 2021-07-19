#include <cstdio>
#include <queue>
using namespace std;
int k, w, h, ans, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, hx[] = { 1,2,2,1,-1,-2,-2,-1 }, hy[] = { -2,-1,1,2,2,1,-1,2 };
int map[205][205], visit[31][205][205];
typedef struct {
	int x, y;
}point;
typedef struct {
	point p;
	int cnt;
}monkey;
queue<monkey> q;
bool safe(int x, int y) { return x >= 0 && x < w && y >= 0 && y < h; }
int bfs() {
	visit[0][0][0] = 1;
	q.push({ {0,0},0 });

	while (!q.empty()) {
		point cur = q.front().p;
		int cnt = q.front().cnt;
		q.pop();

		if (cur.x == w - 1 && cur.y == h - 1) {
			return visit[cnt][cur.y][cur.x] - 1;
		}


		if (cnt<k)
			for (int i = 0; i < 8; i++) {
				int nx = cur.x + hx[i], ny = cur.y + hy[i];
				if (!safe(nx, ny) || visit[cnt+1][ny][nx] || map[ny][nx])continue;
				visit[cnt+1][ny][nx] = visit[cnt][cur.y][cur.x] + 1;
				q.push({ {nx,ny}, cnt+1 });
			}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (!safe(nx, ny) || visit[cnt][ny][nx] || map[ny][nx])continue;
			visit[cnt][ny][nx] = visit[cnt][cur.y][cur.x] + 1;
			q.push({ {nx,ny}, cnt });
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &k, &w, &h);
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
	printf("%d", bfs());
	return 0;
}