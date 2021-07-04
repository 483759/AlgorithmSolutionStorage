//#include <cstdio>
//#include <queue>
//#include <vector>
//#include <cstring>
//#include <math.h>
//using namespace std;
//int n, m, land, map[11][11], dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };
//typedef struct {
//	int r, c;
//}point;
//typedef struct {
//	point p;
//	int dir, len, des;
//}bridge;
//vector<bridge> v;
//queue<bridge> ib;
//queue<point> q;
//bool visit[11][11], check[100];
//int cg[7][7], cv[7], ans = 100000;
//bool safe(int r, int c) {
//	return r >= 0 && r < n && c >= 0 && c < m;
//}
//void erase_bridge() {
//	bool b[4][11][11]; memset(b, false, sizeof(b));
//	while (!ib.empty()) {
//		point p = ib.front().p;
//		point w = p;
//		int dir = ib.front().dir, len = 0;
//		p.r += dr[dir]; p.c += dc[dir];
//		if (b[dir][w.r][w.c]) {
//			ib.pop(); continue;
//		}
//		b[dir][w.r][w.c] = 1;
//
//		while (1) {
//			if (!safe(p.r, p.c)) {	//¸ÊÀ» ¹þ¾î³¯ °æ¿ì
//				break;
//			}
//			if (map[p.r][p.c] != 0) {	//¼¶¿¡ ´êÀ¸¸é
//				len = abs(ib.front().p.r - p.r) + abs(ib.front().p.c - p.c) - 1;
//				if (len < 2)break;
//				v.push_back({ w,dir,len,map[p.r][p.c] });
//				b[(dir + 2) % 4][p.r][p.c] = 1;
//				break;
//			}
//			p.r += dr[dir]; p.c += dc[dir];
//		}
//		ib.pop();
//	}
//}
//void bfs(point p) {
//	q.push(p);
//	visit[p.r][p.c] = 1;
//	map[p.r][p.c] = land;
//
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//
//		for (int i = 0, nr, nc; i < 4; i++) {
//			nr = cur.r + dr[i], nc = cur.c + dc[i];
//			if (safe(nr, nc) && map[nr][nc] && !visit[nr][nc]) {
//				q.push({ nr,nc });
//				visit[nr][nc] = 1;
//				map[nr][nc] = land;
//			}
//			else if (safe(nr, nc) && !map[nr][nc]) {
//				//´Ù¸® ÈÄº¸ »ðÀÔ
//				ib.push({ cur,i,0 });
//			}
//		}
//	}
//}
//void dfs(int cur) {
//	cv[cur] = true;
//	for (int next = 1; next <= land; next++)
//		if (!cv[next] && cg[cur][next])
//			dfs(next);
//}
//void func(int dep) {
//	if (dep == v.size()) {
//		memset(cg, false, sizeof(cg));
//		memset(cv, false, sizeof(cv));
//		int sum = 0;
//		for (int i = 0; i < v.size(); i++) {
//			if (!check[i])continue;
//			int cur = map[v[i].p.r][v[i].p.c];
//			int next = v[i].des;
//			cg[cur][next] = cg[next][cur] = 1;
//			sum += v[i].len;
//		}
//		dfs(1);
//
//		for (int i = 1; i <= land; i++)
//			if (!cv[i])return;
//		if (sum < ans)ans = sum;
//		return;
//	}
//
//	check[dep] = true;
//	func(dep + 1);
//	check[dep] = false;
//	func(dep + 1);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &map[i][j]);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] && !visit[i][j]) {
//				land++;
//				bfs({ i,j });
//			}
//		}
//	//print();
//	erase_bridge();
//	//print_bridgd();
//
//	func(0);
//	printf("%d", ans == 100000 ? -1 : ans);
//	return 0;
//}