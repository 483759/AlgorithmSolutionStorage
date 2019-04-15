#include <cstdio>
struct point { int x, y; };
int n, ans;
bool map[17][17], dx[] = { 1, 1, 0 }, dy[] = { 0, 1, 1 };
bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && !map[y][x];
}
bool canMove(int x, int y, int d) {
	switch (d) {
	case 0:
		return safe(x + 1, y);
	case 1:
		return safe(x + 1, y) && safe(x, y + 1) && safe(x + 1, y + 1);
	case 2:
		return safe(x, y + 1);
	default:
		break;
	}
}
void func(int cx, int cy, int d) {
	int nx = cx + dx[d], ny = cy + dy[d], s, f;
	if ((nx == n - 1) && (ny == n - 1))ans++;
	switch (d) {
	case 0:
		s = 0; f = 1;
		break;
	case 1:
		s = 0; f = 2;
		break;
	case 2:
		s = 1; f = 2;
		break;
	default:
		break;
	}
	for (int i = s; i <= f; i++)
		if (canMove(nx, ny, i))
			func(nx, ny, i);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &map[i][j]);
	func(0, 0, 0);
	printf("%d", ans);
	return 0;
}