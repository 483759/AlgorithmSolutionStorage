#include <cstdio>
#include <queue>
#include <memory.h>
#define safe(x,y) x>=0&&x<n&&y>=0&&y<n
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int n, arr[101][101], ans=1, minh = 101, maxh, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool rain[101][101], visit[101][101];
struct point { int x, y; };
queue<point> q;
void bfs() {
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0, nx, ny; i < 4; i++) {
			nx = cur.x + dx[i]; ny = cur.y + dy[i];
			if (safe(nx, ny) && !rain[ny][nx] && !visit[ny][nx]) {
				q.push({ nx,ny });
				visit[ny][nx] = 1;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		scanf("%d", &arr[i][j]);
		minh = MIN(arr[i][j], minh);
		maxh = MAX(arr[i][j], maxh);
	}
	for (int a = minh; a < maxh; a++) {
		int sum=0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
			if (arr[i][j] <= a)rain[i][j] = 1;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
			if (!rain[i][j] && !visit[i][j]) {
				q.push({ j,i });
				visit[i][j] = 1;
				bfs();
				sum++;
			}
		}
		ans = MAX(ans, sum);
	}
	printf("%d", ans);
	return 0;
}