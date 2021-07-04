#include <cstdio>
#include <cstring>
#define n 6
int T, m, map[7][7], ans[3];
int dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
bool safe(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}
void flip(int x, int y, int dir, int color) {
	int nx = x + dx[dir], ny = y + dy[dir];
	while (safe(nx, ny) && map[ny][nx] && map[ny][nx] != color) {
		nx += dx[dir]; ny += dy[dir];
	}
	if (!map[ny][nx])return;
	while (!(x == nx && y == ny)) {
		map[y][x] = color;
		x += dx[dir]; y += dy[dir];
	}
}
int main() {
	scanf("%d", &m);
	map[n / 2][n / 2] = map[n / 2 + 1][n / 2 + 1] = 1;
	map[n / 2 + 1][n / 2] = map[n / 2][n / 2 + 1] = 2;

	int c = 2;
	while (m--) {
		int x, y;
		scanf("%d%d", &y, &x);

		for (int i = 0; i < 8; i++)
			flip(x, y, i, c);
		c = (c == 1) ? 2 : 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j])
				ans[map[i][j]]++;
			if (map[i][j] == 0)printf(".");
			else if (map[i][j] == 1)printf("W");
			else printf("B");
		}
		printf("\n");
	}
	if (ans[1] > ans[2])printf("White");
	else printf("Black");
	return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//typedef struct { int r, c; }point;
//typedef struct { int r,c,k; }baduk;
//int map[22][22], ans, n, m, dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };
//vector<baduk> cdd[2];
//
//bool safe(int r, int c) { return r > 0 && r <= n && c > 0 && c <= m; }
//
//bool cmp(baduk a, baduk b) { return a.k > b.k; }
//
//vector<baduk> bfs(int r,int c) {
//	queue<point> q;
//	vector<baduk> v;
//	bool visit[22][22] = { 0 };
//	int count = 0;
//
//	q.push({ r,c });
//	visit[r][c] = 1;
//
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		count++;
//
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.r + dr[i], nc = cur.c + dc[i];
//			if (visit[nr][nc])continue;
//			if (map[nr][nc] == 0) {
//				v.push_back({ nr,nc,0 });
//			}
//			if (map[nr][nc] == 2) {
//				q.push({ nr,nc });
//			}
//			visit[nr][nc] = 1;
//		}
//	}
//
//	for (int i = 0; i < v.size(); i++)v[i].k = count;
//	return v;
//}
//
//int main() {
//	scanf("%d%d", &n, &m);
//
//	memset(map, 1, sizeof(map));
//	for (int i = 1; i <= n; i++) 
//		for (int j = 1; j <= m; j++)
//			scanf("%d", &map[i][j]);
//
//	bool visit[22][22] = { 0 };
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			if (map[i][j] == 2&&!visit[i][j]) {
//				int e = 0;
//				for (int k = 0; k < 4; k++) {
//					int nr = i + dr[k], nc = j + dc[k];
//					if (map[nr][nc] == 0) {
//						e++;
//					}
//
//				}
//				if (!e)continue;
//
//				vector<baduk> lump=bfs(i, j);
//
//				if (lump.size() == 1) {
//					cdd[0].
//					cdd[0].push_back({ i,j,lump });
//				}
//				else if (lump.size() == 2) {
//					cdd[1].push_back({ i,j,lump });
//				}
//			}
//
//	//if (cdd.size() == 0) { printf("0"); return 0; }
//	//vector<bool> ps(cdd.size(), false);
//	//ps[ps.size() - 1] = true;
//	//if (cdd.size() > 1)ps[ps.size() - 2] = true;
//
//	//for (int i = 0; i < cdd.size(); i++)
//	//	for (int j = i + 1; j < cdd.size(); j++) {
//	//		map[cdd[i].r][cdd[i].c] = map[cdd[j].r][cdd[j].c] = 1;
//
//	//		bfs();
//
//	//		map[cdd[i].r][cdd[i].c] = map[cdd[j].r][cdd[j].c] = 0;
//	//	}
//	printf("%d", ans);
//	return 0;
//}