#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, m, e, ans = 987654321, map[51][51], visit[51][51], dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };
typedef struct {
	int r, c;
}point;
vector<point> v;
queue<point> q;
int check[11];
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}
void dfs(int dep, int num) {
	if (dep == m) {
		memset(visit, -1, sizeof(visit));
		int sum = 0, t = 0;
		for (int i = 0; i < m; i++) {
			q.push(v[check[i]]);
			visit[v[check[i]].r][v[check[i]].c] = 0;
		}

		while (!q.empty()) {
			point cur = q.front(); q.pop();
			for (int i = 0, nr, nc; i < 4; i++) {
				nr = cur.r + dr[i], nc = cur.c + dc[i];
				if (map[nr][nc] == 1 || visit[nr][nc] >= 0||!safe(nr,nc))continue;
				q.push({ nr,nc });
				visit[nr][nc] = visit[cur.r][cur.c] + 1;
				if (!map[nr][nc]) {
					sum++;
					if (visit[nr][nc] > t)t = visit[nr][nc];
				}
			}
		}
		if (sum == e)
			ans = t < ans ? t : ans;
		return;
	}

	for (int i = num; i < v.size(); i++) {
		check[dep] = i;
		dfs(dep + 1, i + 1);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (!map[i][j])e++;
			if (map[i][j] == 2)v.push_back({ i,j });
		}
	dfs(0, 0);
	printf("%d", ans ==987654321 ? -1 : ans);
	return 0;
}