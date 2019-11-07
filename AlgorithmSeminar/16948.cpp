#include <cstdio>
#include <queue>
#define safe(r,c) r>=0&&r<n&&c>=0&&c<n
using namespace std;
struct point { int r, c, d; };
int n, r1, c1, r2, c2, dr[] = { -2,-2,0,0,2,2 }, dc[] = {-1,1,-2,2,-1,1};
bool v[201][201];
queue<point> q;
int bfs() {
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0, nr, nc; i < 6; i++) {
			nr = cur.r + dr[i]; nc = cur.c + dc[i];
			if (nr == r2 && nc == c2)return cur.d+1;
			if (safe(nr, nc) && !v[nr][nc]) {
				q.push({ nr,nc,cur.d+1 });
				v[nr][nc] = 1;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	q.push({ r1,c1,0 });
	v[r1][c1] = true;
	printf("%d", bfs());
	return 0;
}