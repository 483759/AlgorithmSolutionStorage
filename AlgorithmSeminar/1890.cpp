#include <cstdio>
int n, a, t;
int main() {
	scanf("%d", &a);
	for (n = 0; a >= 3 * n*n - 3 * n + 2; n++);
	printf("%d", a==1?1:n);
	return 0;
}
//#include <cstdio>
//#include <queue>
//#define safe(x,y) x>=0&&x<n&&y>=0&&y<n
//using namespace std;
//int n, ans, map[101][101], dx[] = { 1,0 }, dy[] = { 0,1 };
//bool visit[101][101];
//struct point { int x, y; };
//bool dfs(point cur) {
//	for (int i = 0, nx, ny; i < 2; i++) {
//		nx = cur.x + dx[i] * map[cur.y][cur.x];
//		ny = cur.y + dy[i] * map[cur.y][cur.x];
//		if ((nx == n - 1 && ny == n - 1) || visit[ny][nx]) {
//			ans++; return true;
//		}
//		if (safe(nx, ny))
//			visit[cur.y][cur.x] = dfs({ nx,ny });
//	}
//	return false;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%d", &map[i][j]);
//	dfs({ 0,0 });
//	printf("%d", ans);
//	return 0;
//}