#include <cstdio>
#include <math.h>
int n, r, c,ans;
bool include(int sx, int sy, int fx, int fy) {
	return r >= sy && r <= fy && c >= sx && c <= fx;
}
void func(int dep, int sx, int sy, int fx, int fy,int num) {
	if (ans)return;
	if (dep > n) {
		ans = num;
	}
	else {
		int k = pow(4, n - dep);
		int nx = (sx + fx) / 2, ny = (sy + fy) / 2;
		if (include(sx,sy,nx,ny))
			func(dep + 1, sx, sy, nx,ny,num);
		else if (include(nx+1,sy,fx,ny))
			func(dep + 1,nx+ 1, sy, fx, ny,num+k);

		else if (include(sx,ny+1,nx,fy))
			func(dep + 1, sx, ny + 1, nx, fy,num+k*2);
		else if (include(nx+1,ny+1,fx,fy))
			func(dep + 1, nx + 1, ny + 1, fx, fy,num+k*3);
	}
	return;
}
int main() {
	scanf("%d%d%d", &n, &r, &c); r++; c++;
	func(1, 1, 1, pow(2, n), pow(2, n),0);
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <cstring>
//int tc, n, map[21][21], ans, dx[] = { -1,1,1,-1 }, dy[] = { -1,-1,1,1 };
//bool num[101];
//typedef struct {
//	int x, y;
//}point;
//point s;
//bool safe(point p) { return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n; }
//void func(point cur,int dep, int sum) {
//	if (dep > 3)return;
//	point p = cur;
//	p.x += dx[dep], p.y += dy[dep];
//	if (dep == 3 && p.x == s.x && p.y == s.y && sum > ans) {
//		ans = sum; return;
//	}
//	if (!safe(p) || num[map[p.y][p.x]])return;
//	num[map[p.y][p.x]] = 1;
//	func(p, dep, sum + 1);
//
//	if (dep < 3)func(p, dep + 1, sum + 1);
//	num[map[p.y][p.x]] = 0;
//
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int T = 1; T <= tc; T++) {
//		ans = -1;
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
//			scanf("%d", &map[i][j]);
//
//		for(int i=2;i<n;i++)
//			for (int j = 1; j < n; j++) {
//				memset(num, 0, sizeof(num));
//				num[map[i][j]] = 1;
//				s = { j,i };
//				func({ j,i }, 0, 1);
//			}
//
//		printf("#%d %d\n", T, ans);
//	}
//	return 0;
//}