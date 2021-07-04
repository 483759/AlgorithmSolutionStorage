#include <cstdio>
#include <queue>
using namespace std;

typedef struct { int x, y, k; }point;

int n, m, t, map[101][101], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[2][101][101];

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	queue<point> q;
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;

	for (int time = 0, size = 0;time<t; time++) {
		size = q.size();
		while (size--) {
			point cur = q.front(); q.pop();
			if (cur.x == m - 1 && cur.y == n - 1) {
				printf("%d", time);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
				if ((cur.k == 1 || map[ny][nx] == 2) && !visit[1][ny][nx]) {
					visit[1][ny][nx] = 1;
					q.push({ nx,ny,1 });
				}
				else {
					if (!visit[0][ny][nx] && map[ny][nx] == 0) {
						visit[0][ny][nx] = 1;
						q.push({ nx,ny,0 });
					}
				}

			}
		}
	}
	printf("Fail");
	return 0;
}