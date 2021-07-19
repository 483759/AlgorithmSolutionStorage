#include <cstdio>
#include <queue>
using namespace std;
char map[251][251];
bool visit[251][251];
int r, c, s, w, dc[] = { 1,0,-1,0 }, dr[] = { 0,1,0,-1 };
struct point { int r, c; };
queue<point> q;
bool safe(int x, int y) {
	return x >= 0 && x < c && y >= 0 && y < r && map[y][x] != '#';
}
void bfs(int cr, int cc) {
	int o = 0, v = 0;
	q.push({ cr,cc });
	visit[cr][cc] = true;
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		if (map[cur.r][cur.c] == 'o')o++;
		else if (map[cur.r][cur.c] == 'v')v++;
		for (int i = 0, nr, nc; i < 4; i++) {
			nr = cur.r + dr[i]; nc = cur.c + dc[i];
			if (safe(nc, nr) && map[nr][nc] != '#' && !visit[nr][nc]) {
				q.push({ nr,nc });
				visit[nr][nc] = true;
			}
		}
	}
	if (o > v)s += o;
	else w += v;
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)scanf("%s", map[i]);
	for (int i = 0; i<r; i++)
		for (int j = 0; j < c; j++) {
			if (map[i][j] != '#' && !visit[i][j]) {
				bfs(i, j);
			}
		}
	printf("%d %d", s, w);
	return 0;
}