#include <cstdio>
#include <queue>
#include <vector>
#define safe(x,y) x>=0&&x<c&&y>=0&&y<r&&a[y][x]!=-1
using namespace std;
struct point { int x, y; };
int r, c, t, ans, d, a[1001][1001], dx[] = { 1,0,-1,0 }, dy[2][4] = { {0,-1,0,1},{0,1,0,-1} };
queue<pair<point, int>> q;
vector<point> v;
void dust(int x, int y) {
	int &s = a[y][x]; d = 0;
	for (int i = 0, nx, ny; i < 4; i++) {
		nx = x + dx[i]; ny = y + dy[0][i];
		if (safe(nx, ny) && a[ny][nx] != -1) {
			q.push({ {nx,ny},s / 5 });
			d++;
		}
	}
	s -= (s / 5)*d;
}
void airclean(int x, int y, int dir) {
	point cur = { x,y }, n = { x + 1,y }, temp = n;
	for (int i = 0, pre = 0, post; i < 4; i++) {
		n = { cur.x + dx[i],cur.y + dy[dir][i] };
		while (safe(n.x, n.y)) {
			if (!dir&&n.y > y)break;
			if (dir&&n.y < y)break;		
			post = a[n.y][n.x];
			a[n.y][n.x] = pre;
			pre = post; if (safe(n.x, n.y))cur = n;
			n = { cur.x + dx[i % 4],cur.y + dy[dir][i] };
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &r, &c, &t);
	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++) {
		scanf("%d", &a[i][j]);
		if (a[i][j] == -1)v.push_back({ j,i });
	}
	for (int i = 0; i < t; i++) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0)dust(j, i);
			}
		while (!q.empty()) {
			point p = q.front().first;
			int s = q.front().second; q.pop();
			a[p.y][p.x] += s;
		}
		airclean(v[0].x, v[0].y, 0);
		airclean(v[1].x, v[1].y, 1);
	}
	for (int l = 0; l < r; l++)
		for (int j = 0; j < c; j++)ans += a[l][j];
	printf("%d", ans + 2);
	return 0;
}