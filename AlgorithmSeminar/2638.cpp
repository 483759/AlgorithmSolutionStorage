#include <cstdio>
#include <queue>
#include <memory>
using namespace std;
int n, m, leave, ans, map[101][101], visit[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0,1,0,-1 };
struct p { int r, c; };
queue<p> q;
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
void func() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int count = 0;
			if (!map[i][j] || map[i][j] == 4)continue;
			for (int k = 0; k < 4; k++) {
				int tr = i + dy[k], tc = j + dx[k];
				if (safe(tr, tc)
					&& map[tr][tc] == 4)count++;
			}
			if (count >= 2)map[i][j] = 3;
		}
}
void bfs(int r, int c) {
	visit[r][c] = true;
	q.push({ r,c });
	map[r][c] = 4;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int tr = cur.r + dy[k], tc = cur.c + dx[k];
			if (safe(tr, tc) && !map[tr][tc] && !visit[tr][tc]) {
				visit[tr][tc] = true;
				q.push({ tr,tc });
				map[tr][tc] = 4;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &map[i][j]);
	do {
		memset(visit, false, sizeof(visit));
		leave = 0; ans++;
		bfs(0, 0);
		func();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 3 || map[i][j] == 4)map[i][j] = 0;
				else if (map[i][j])leave++;
			}
	} while (leave);
	printf("%d", ans);
	return 0;
}