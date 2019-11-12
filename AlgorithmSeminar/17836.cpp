#include <cstdio>
#include <queue>
using namespace std;
struct point { int r, c, t; };
int n, m, t, ans=5001, map[101][101], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[101][101];
queue<point> q;
int gram=5001, walk=5001;
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
void bfs() {
	visit[0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0, tr, tc; i < 4; i++) {
			tr = cur.r + dy[i], tc = cur.c + dx[i];
			if (tr == n - 1 && tc == m - 1)walk = cur.t+1;
			if (safe(tr, tc) && !visit[tr][tc] && map[tr][tc] != 1) {
				if (map[tr][tc] == 2)gram = cur.t + n - tr + m - 1 - tc;
				visit[tr][tc] = 1;
				q.push({ tr,tc,cur.t + 1 });
			}
		}
	}
	ans= gram < walk ? gram : walk;
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &map[i][j]);
	bfs();
	if (ans <= t)printf("%d", ans);
	else printf("Fail");
	return 0;
}