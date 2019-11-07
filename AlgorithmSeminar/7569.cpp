#include <cstdio>
#include <queue>
#define safe(x,y,z) x>=0&&x<m&&y>=0&&y<n&&z>=0&&z<h
using namespace std;
int m, mx, n, h, ans=1,zero;
int map[101][101][101], dx[] = { 1,0,0,-1,0,0 }, dy[] = { 0,1,0,0,-1,0 }, dz[] = { 0,0,1,0,0,-1 };
int visit[101][101][101];
struct point { int x, y, z; };
queue<point> q;
void bfs() {
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0, nx, ny, nz; i < 6; i++) {
			nx = cur.x + dx[i]; ny = cur.y + dy[i]; nz = cur.z + dz[i];
			if (safe(nx, ny, nz) && map[nz][ny][nz] == 0 && !visit[nz][ny][nx]) {
				zero--;
				visit[nz][ny][nx] = visit[cur.z][cur.y][cur.x]+1;
				ans = visit[nz][ny][nx] > ans ? visit[nz][ny][nx]:ans;
				q.push({ nx, ny, nz });
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[k][i][j]);
				if (map[k][i][j] == 1) {
					q.push({ j,i,k });
					visit[k][i][j] = 1;
				}
				if (!map[k][i][j])zero++;
			}
	bfs();
	if (zero)printf("-1");
	else printf("%d", ans-1);
	return 0;
}