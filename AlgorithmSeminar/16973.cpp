#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, m, ans = 100000, sr, sc, fr, fc, w, h, map[1001][1001], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int v[1001][1001];
struct point { int r, c; };
bool safe(int r, int c) {
	return r >= 1 && r + h - 1 <= n && c >= 1 && c + w - 1 <= m && map[r][c] != 1;
}
void bfs(point c, int dep, int dir) {
	if (c.r == fr && c.c == fc) {
		ans = dep < ans ? dep : ans;
		return;
	}
	bool sf[4];
	for (int i = 0; i < 4; i++)sf[i] = true;
	v[c.r][c.c] = dep;
	for (int i = 0, nr, nc, t; i < 4; i++) {
		if (i == dir)continue;
		nr = c.r + dy[i]; nc = c.c + dx[i];
		//if (safe(nr, nc) && sf[i] && dep < v[nr][nc]) {
		//	bfs({ nr,nc }, dep + 1, (i + 2) % 4);
		//}
		switch (i) {
		case 0:
			for (int k = 0; k < h; k++)
				if (!safe(c.r + k, c.c + 1))sf[0] = false;
			break;
		case 1:
			for (int k = 0; k < w; k++)
				if (!safe(c.r + 1, c.c + k))sf[1] = false;
			break;
		case 2:
			for (int k = 0; k < h; k++)
				if (!safe(c.r + k, c.c - 1))sf[2] = false;
			break;
		case 3:
			for (int k = 0; k < h; k++)
				if (!safe(c.r - 1, c.c + k))sf[3] = false;
			break;
		}
		if (sf[i] && dep < v[nr][nc])
			bfs({ nr,nc }, dep + 1, (i + 2) % 4);
	}
	//for (int i = c.c, cr = c.r; i < c.c + w; i++) {
	//	if (!safe(cr - 1, i) || map[cr - 1][i])sf[3] = 0;
	//	if (!safe(cr + 1, i) || map[cr + 1][i])sf[1] = 0;
	//}
	//for (int i = c.r, cc = c.c; i < c.r + h; i++) {
	//	if (!safe(i, cc - 1) || map[i][cc - 1])sf[2] = 0;
	//	if (!safe(i, cc + 1) || map[i][cc + 1])sf[0] = 0;
	//}
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	fill(&v[0][0], &v[1001][1001], 1000000);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)
		scanf("%d", &map[i][j]);
	scanf("%d%d%d%d%d%d", &h, &w, &sr, &sc, &fr, &fc);
	bfs({ sr,sc }, 0, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%8d ", v[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("%d", ans == 100000 ? -1 : ans);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//int n, m, ans = 100000, sr, sc, fr, fc, w, h, map[1001][1001], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//int v[1001][1001];
//struct point { int r, c; };
//bool safe(int r, int c) {
//	return r >= 1 && r + h - 1 <= n && c >= 1 && c + w - 1 <= m;
//}
//void bfs(point c, int dep, int dir) {
//	if (c.r == fr && c.c == fc) {
//		ans = dep < ans ? dep : ans;
//		return;
//	}
//	bool sf[4];
//	for (int i = 0; i < 4; i++)sf[i] = true;
//	v[c.r][c.c] = dep;
//	for (int i = c.c, cr = c.r; i < c.c + w; i++) {
//		if (!safe(cr - 1, i) || map[cr - 1][i])sf[3] = 0;
//		if (!safe(cr + 1, i) || map[cr + 1][i])sf[1] = 0;
//	}
//	for (int i = c.r, cc = c.c; i < c.r + h; i++) {
//		if (!safe(i, cc - 1) || map[i][cc - 1])sf[2] = 0;
//		if (!safe(i, cc + 1) || map[i][cc + 1])sf[0] = 0;
//	}
//	if (dep)sf[dir] = 0;
//	for (int i = 0, nr, nc, t; i < 4; i++) {
//		nr = c.r + dy[i]; nc = c.c + dx[i];
//		if (safe(nr, nc) && sf[i] && dep < v[nr][nc]) {
//			bfs({ nr,nc }, dep + 1, (i + 2) % 4);
//		}
//	}
//	return;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	fill(&v[0][0], &v[1001][1001], 1000000);
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)
//		scanf("%d", &map[i][j]);
//	scanf("%d%d%d%d%d%d", &h, &w, &sr, &sc, &fr, &fc);
//	bfs({ sr,sc }, 0, 0);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%8d ", v[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//	printf("%d", ans == 100000 ? -1 : ans);
//	return 0;
//}