#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef struct {
	int x, y;
}point;
int ans,n, m, map[301][301], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[301][301];
queue<point> q;
queue<pair<int,point>> melt;
bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
void bfs(point p) {
	visit[p.y][p.x] = 1;
	q.push(p);
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (safe(nx, ny) && !visit[ny][nx] && map[ny][nx]) {
				visit[ny][nx] = 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	while (1) {
		bool b = false; memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!b && map[i][j]) {
					bfs({ j,i });
					b = 1;
				}
				else if (b && map[i][j]&&!visit[i][j]) {
					printf("%d", ans);
					return 0;
				}
		if (!b) { printf("0"); return 0; }
		ans++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j]) {
					int t = 0; point cur = { j,i };
					for (int k = 0; k < 4; k++)
						if (!map[i + dy[k]][j + dx[k]])t++;
					melt.push(make_pair(t, cur));
				}

		while (!melt.empty()) {
			int k = melt.front().first;
			point p = melt.front().second;
			map[p.y][p.x] -= k;
			if (map[p.y][p.x] < 0)map[p.y][p.x] = 0;
			melt.pop();
		}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++)
		//		printf("%d ", map[i][j]);
		//	printf("\n");
		//}printf("\n");
	}
	return 0;
}