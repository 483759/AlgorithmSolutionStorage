#include <cstdio>
#include <queue>
#include <stack>
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
typedef struct {
	int x, y;
}point;
queue<point> q;
stack<point> s;
int n, a[51][51], l, r, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, ans;
bool visit[51][51], b = true;
bool func(int a, int b) {
	return abs(a - b) >= l && abs(a - b) <= r;
}
bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && !visit[y][x];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &a[i][j]);

	while (b) {
		memset(visit, false, sizeof(visit));
		b = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {	//이동할 국가 탐색
				if (visit[i][j])continue;
				if (!(
					(func(a[i][j], a[i + 1][j]) && safe(j, i + 1))
					|| (func(a[i][j], a[i][j + 1]) && safe(j + 1, i))
					))continue;

				int sum = 0, con = 0; b = true;

				visit[i][j] = 1; q.push({ j,i });
				sum += a[i][j]; con++;
				s.push({ j,i });
				while (!q.empty()) {
					point cur = q.front(); q.pop();
					for (int k = 0, nx, ny; k < 4; k++) {
						nx = cur.x + dx[k], ny = cur.y + dy[k];
						if (safe(nx, ny) && func(a[cur.y][cur.x], a[ny][nx])) {
							//방문한 적 없고 차이가 L이상 R이하라면
							visit[ny][nx] = 1;
							q.push({ nx,ny });
							sum += a[ny][nx], con++;
							s.push({ nx,ny });
						}
					}
				}

				while (!s.empty()) {
					point cur = s.top(); s.pop();
					a[cur.y][cur.x] = sum / con;
				}


			}
		ans++;
	}
	printf("%d", ans-1);
	return 0;
}