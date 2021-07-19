#include <cstdio>
#include <stack>
#define safe(x,y) x>=0&&x<n&&y>=0&&y<n
using namespace std;
int n, ans, sum, dx[] = { 1,0,-1,0,1,1,-1,-1 }, dy[] = { 0,1,0,-1,1,-1,-1,1 };
bool v[16][16], b;
struct point { int x, y; };
stack<point> s;
void func(int dep) {
	if (dep == n)return;
	for (int i = 0; i < n; i++) {
		if (v[dep][i])continue;
		int q = 1;
		v[dep][i] = 1;
		s.push({ i,dep });
		for (int j = 0, nx, ny; j < 8; j++) {
			nx = i + dx[j]; ny = dep + dy[j];
			while (safe(nx, ny)) {
				if (!v[ny][nx]) {
					s.push({ nx,ny });
					q++;
					v[ny][nx] = 1;
				}
				nx += dx[j]; ny += dy[j];
			}
		}
		if (dep == n - 1 && s.size() == n * n)ans++;
		func(dep + 1);
		while (q--) {
			point p = s.top(); s.pop();
			v[p.y][p.x] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	func(0);
	printf("%d", ans);
	return 0;
}