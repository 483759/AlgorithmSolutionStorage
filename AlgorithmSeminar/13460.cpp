#include <cstdio>
int n, m, ans = 11, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char map[11][11];
bool br, bb;
struct point { int x, y; };
point r, b, o;
bool safe(point p, int d) {
	int nx = p.x + dx[d], ny = p.y + dy[d];
	return map[ny][nx] != '#'&&map[ny][nx] != 'R'&&map[ny][nx] != 'B';
}
bool move(point& p, int d, char c) {
	map[p.y][p.x] = '.';
	while (safe(p, d)) {
		p.x += dx[d]; p.y += dy[d];
		if (p.x==o.x&&p.y==o.y) return true;
	}
	map[p.y][p.x] = c;
	return false;
}
void func(point cr, point cb, int dep, int pre) {
	if (dep > 10) {
		map[cr.y][cr.x] = map[cb.y][cb.x]='.';
		return;
	}
	point pr, pb;
	for (int i = 0; i < 4; i++) {
		if (!safe(cr, i) && !safe(cb, i) || i == (pre + 2) % 4) continue;
		pr = cr; pb = cb;
		br = move(cr, i, 'R');
		bb = move(cb, i, 'B');
		printf("%d\n", dep);
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < m; j++)
				printf("%c", map[k][j]);
			printf("\n");
		}
		printf("\n");
		if (br && !bb) {
			ans = dep < ans ? dep : ans;
			return;
		}
		func(cr, cb, dep + 1, i);
		cr = pr; cb = pb;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" ");
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'R')r = { j,i };
			else if (map[i][j] == 'B')b = { j,i };
			else if (map[i][j] == 'O')o = { j,i };
		}
	}
	func(r, b, 1, -4);
	printf("%d", ans <= 10 ? ans : -1);
	return 0;
}