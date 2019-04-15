#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct point { int x, y; };
int n, m, ans, t, map[21][21], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool visit[21][21];
vector<point> p;
queue<point> q;
bool safe(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}
int bfs(int x, int y) {
	visit[y][x] = true;
	q.push({ x, y });
	int num = 1, e = 1;
	while (!q.empty()) {
		int cx = q.front().x, cy = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (safe(nx, ny) && map[ny][nx] == 2 && !visit[ny][nx]) {
				num++;
				visit[ny][nx] = true;
				q.push({ nx,ny });
			}
			else if (safe(nx, ny) && map[ny][nx] % 3 == 0)e = 0;
		}
	}
	if (!e)return 0;
	return num;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &map[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 2)continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k], ny = i + dy[k];
				if (safe(nx, ny) && !map[ny][nx]) {
					map[ny][nx] = 3;
					p.push_back({ nx,ny });
				}
			}
		}
	for (int i = 0; i < p.size(); i++)
		for (int j = i + 1; j < p.size(); j++) {
			t = 0;
			memset(visit, false, sizeof(visit));
			map[p[i].y][p[i].x] = 1; map[p[j].y][p[j].x] = 1;
			for (int k = 0; k < n; k++)
				for (int l = 0; l < m; l++)
					if (map[k][l] == 2 && !visit[k][l]) {
						t += bfs(l, k);
					}
			map[p[i].y][p[i].x] = 3; map[p[j].y][p[j].x] = 3;
			ans = t > ans ? t : ans;
		}
	printf("%d", ans);
	return 0;
}