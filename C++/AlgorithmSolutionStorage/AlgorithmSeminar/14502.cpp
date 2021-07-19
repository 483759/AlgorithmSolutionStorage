#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
#define safe(r,c) r>=0&&r<n&&c>=0&&c<m
using namespace std;
struct point { int r, c; };
int n, m,ans,num, map[9][9], dr[] = { 1,0,-1,0 }, dc[] = {0,1,0,-1};
bool visit[9][9];
vector<point> v, t;
queue<point> q;
void bfs(point p) {
	visit[p.r][p.c] = 1;
	q.push({ p.r,p.c });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0,nr,nc; i < 4; i++) {
			nr = cur.r + dr[i], nc = cur.c + dc[i];
			if (safe(nr,nc)&&!map[nr][nc]&&!visit[nr][nc]) {
				visit[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		if (!map[i][j])v.push_back({ i,j });

	for (int i = 0; i < v.size() - 2; i++)
		for (int j = i + 1; j < v.size() - 1; j++)
			for (int k = j + 1; k < v.size(); k++) {
				if (map[v[i].r][v[i].c] || map[v[j].r][v[j].c] || map[v[k].r][v[k].c])continue;
				int cnt = 0;
				map[v[i].r][v[i].c] = map[v[j].r][v[j].c] = map[v[k].r][v[k].c] = 1;

				for(int x=0;x<m;x++)
					for (int y = 0; y < n; y++)
						if(map[y][x]==2)bfs({ y,x });

				for (int x = 0; x < m; x++)
					for (int y = 0; y < n; y++)
						if (!visit[y][x]&&!map[y][x])cnt++;

				ans = cnt > ans ? cnt : ans;
				memset(visit, false, sizeof(visit));
				while (!q.empty())q.pop();
				map[v[i].r][v[i].c] = map[v[j].r][v[j].c] = map[v[k].r][v[k].c] = 0;
			}

	printf("%d", ans);
	return 0;
}