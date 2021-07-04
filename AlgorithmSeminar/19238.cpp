#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct { int r, c; }point;
struct cmp {
	bool operator()(point a, point b) {
		if (a.r == b.r)return a.c > b.c;
		return a.r > b.r;
	}
};
int n, m, e, map[25][25], dr[] = { -1,0,0,1 }, dc[] = { 0,-1,1,0 };
point t,des[405];
point bfs(bool k,int num) {
	int visit[25][25],dist=-1; fill(&visit[0][0], &visit[n + 2][n + 2], -1);
	queue<point> q; priority_queue<point, vector<point>, cmp> pq;
	point v = des[num];

	visit[t.r][t.c] = 0;
	q.push({ t.r,t.c });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		if (dist != -1 && visit[cur.r][cur.c] > dist)continue;
		if (k && (map[cur.r][cur.c] > 0)) {
				pq.push(cur);
				dist = visit[cur.r][cur.c];
		}
		if ((!k&&(cur.r==v.r&&cur.c==v.c))) {
			e -= visit[cur.r][cur.c];
			return cur;
		}
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i], nc = cur.c + dc[i];
			if (map[nr][nc] == -1 || visit[nr][nc] >= 0)continue;
			visit[nr][nc] = visit[cur.r][cur.c] + 1;
			q.push({ nr,nc });
		}
	}
	if(pq.empty())return { -1,-1 };
	e -= dist;
	return pq.top();

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &e);
	fill(&map[0][0], &map[n + 2][n + 2], -1);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) {
		scanf("%d", &map[i][j]);
		if (map[i][j] == 1)map[i][j] = -1;
	}scanf("%d%d", &t.r, &t.c);
	for (int i = 1; i <= m; i++) {
		int sr, sc, fr, fc;
		scanf("%d%d%d%d", &sr, &sc, &fr, &fc);
		map[sr][sc] = i; des[i] = { fr,fc };
	}
	while (m--) {
		t=bfs(1, 0);
		if ((t.r == -1) || (e <= 0)) { printf("-1"); return 0; }
		int num = map[t.r][t.c],cost=e;
		map[t.r][t.c] = 0;
		t = bfs(0, num);
		if ((t.r == -1) || (e < 0)) { printf("-1"); return 0; }
		e += (cost - e) * 2;
	}printf("%d", e);
	return 0;
}
//#include <cstdio>
//#include <queue>
//#include <vector>
//using namespace std;
//
//typedef struct { int r, c; }point;
//int n, m, e, dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };
//int map[21][21], dist;
//vector<point> p;
//point taxi;
//bool safe(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }
//struct cmp {
//	bool operator()(point t, point u) {
//		if (t.r == u.r)return t.c > u.c;
//		return t.r > u.r;
//	}
//};
//point toDestination(bool b, point des) {
//	int visit[21][21]; for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)visit[i][j] = -1;
//	queue<point> q;
//	vector<point> v;
//	priority_queue<point, vector<point>, cmp> pq;
//	dist = -1;
//
//	visit[taxi.r][taxi.c] = 0;
//	q.push(taxi);
//
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//
//		if (!b && cur.r == des.r && cur.c == des.c) { dist = visit[cur.r][cur.c]; return cur; }
//		if (b && map[cur.r][cur.c] > 0) {
//			if (dist == -1)dist = visit[cur.r][cur.c];
//			if (dist == visit[cur.r][cur.c])
//				pq.push(cur);
//		}
//
//		if (b && dist != -1)continue;
//
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.r + dr[i], nc = cur.c + dc[i];
//			if (!safe(nr, nc) || map[nr][nc] == -1 || visit[nr][nc] != -1)continue;
//
//			visit[nr][nc] = visit[cur.r][cur.c] + 1;
//			q.push({ nr,nc });
//		}
//	}
//	if (dist == -1)return { -1,-1 };
//	e -= dist;
//	return pq.top();
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &e);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &map[i][j]);
//			if (map[i][j])map[i][j] = -1;
//		}
//	int tr, tc; scanf("%d%d", &tr, &tc);
//	taxi = { tr - 1,tc - 1 }; p.push_back({ -1,-1 });
//	for (int i = 1; i <= m; i++) {
//		int a, b, c, d;
//		scanf("%d%d%d%d", &a, &b, &c, &d);
//		map[a - 1][b - 1] = i;
//		p.push_back({ c - 1,d - 1 });
//	}
//	while (m--) {
//		taxi = toDestination(1,taxi);
//		if (e < 0 || taxi.r < 0) { printf("-1"); return 0; }
//		point des = p[map[taxi.r][taxi.c]];
//		map[taxi.r][taxi.c] = 0;
//		toDestination(0,des);
//		if (e < dist || dist == -1) { printf("-1"); return 0; }
//		e += dist;
//		taxi = des;
//	}
//	printf("%d", e);
//	return 0;
//}