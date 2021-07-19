#include <cstdio>
#include <algorithm>
#include <queue>
#define safe(x,y) x>=0&&x<m&&y>=0&&y<n
using namespace std;
int n, m, p, s[10], e, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, ans[10];
char map[1001][1001];
bool v[1001][1001],b=1;
struct point { int x, y; };
queue<point> q[10];
void bfs(int h) {
	for (int k = 0; k < s[h]; k++) {
		if (q[h].empty() || !e)return;
		int t = q[h].size();
		while (t--) {
			point cur = q[h].front(); q[h].pop();
			for (int i = 0, nx, ny; i < 4; i++) {
				nx = cur.x + dx[i]; ny = cur.y + dy[i];
				if (safe(nx, ny) && !v[ny][nx] && map[ny][nx] == '.') {
					v[ny][nx] = true;
					q[h].push({ nx,ny });
					map[ny][nx] = h+'0';
					e--; ans[h]++;
				}
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= p; i++)scanf("%d", &s[i]);
	for (int i = 0; i < n; i++) {
		scanf(" ");
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] >= '1') {
				q[map[i][j] - '0'].push({ j,i });
				v[i][j] = true;
				ans[map[i][j] - '0']++;
			}
			if (map[i][j] == '.')e++;
		}
	}
	while (e&&b) {
		b = 0;
		for (int i = 1; i < 10; i++)
			if (!q[i].empty()) { bfs(i); b = 1; }
	}
	for (int i = 1; i <= p; i++)printf("%d ", ans[i]);
	return 0;
}
//printf("\n");
//for (int i = 0; i < n; i++) {
//	for (int j = 0; j < m; j++)
//		printf("%c ", map[i][j]);
//	printf("\n");
//}
//int n, m, p, e, visit[1001][1001], ans[10], s[10], dx[] = { 1, 0, -1,0 }, dy[] = { 0,1,0,-1 };
//char map[1001][1001];
//struct point { int x, y, d, r; };
//queue<point> q;
//bool operator<(point a, point b) {
//	if (a.r == b.r)return a.d > b.d;
//	return a.r > b.r;
//
//}
//void bfs(int x, int y, int c, int r) {
//	q.push({ x,y,s[c],r });
//	visit[y][x] = 1;
//	while (!q.empty() && e) {
//		point cur = q.front(); q.pop();
//		for (int i = 0, nx, ny, nd; i < 4; i++) {
//			nx = cur.x + dx[i]; ny = cur.y + dy[i]; nd = cur.d;
//			if (safe(nx, ny) && map[ny][nx] == '.' && !visit[ny][nx] && nd) {
//				q.push({ nx,ny,nd - 1,r });
//				pq.push({ nx,ny,c,r + 1 });
//				map[ny][nx] = c + '0';
//				visit[ny][nx] = 1;
//				ans[c]++; e--;
//			}
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &p);
//	e = n * m;
//	for (int i = 1; i <= p; i++)scanf("%d", &s[i]);
//	for (int i = 0; i < n; i++) {
//		scanf(" ");
//		for (int j = 0; j < m; j++) {
//			scanf("%c", &map[i][j]);
//			if (map[i][j] >= '1'&&map[i][j] < '9') {
//				pq.push({ j, i, map[i][j] - '0',1 });
//				ans[map[i][j] - '0']++;
//			}
//			if (map[i][j] != '.')e--;
//		}
//	}
//	while (e && !pq.empty()) {
//		point p = pq.top(); pq.pop();
//		bfs(p.x, p.y, p.d, p.r);
//	}
//	for (int i = 1; i <= p; i++)
//		printf("%d ", ans[i]);
//	return 0;
//}