#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct { int x, y, d; }point;
int T,n,c, map[15][15], e, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 },ans,len=987654321;
bool visit[15][15];
vector<point> v;
void dfs(int dep,int core,int wire) {
	if (dep == v.size()) {
		if (core > ans) {
			ans = core;
			len = wire;
		}
		else if (core == ans && wire < len)
			len = wire;
		return;
	}

	dfs(dep + 1,core,wire);
	for (int i = 0; i < 4; i++) {
		//v[dep].d = i;

		point p = v[dep];
		int d = 0;
		p.x += dx[i]; p.y += dy[i];
		while (!map[p.y][p.x] && !visit[p.y][p.x]) {
			p.x += dx[i]; p.y += dy[i];
			d++;
		}

		if (map[p.y][p.x] != -1)continue;

		for (int j = 0; j < d; j++) {
			visit[v[dep].y + dy[i] * j][v[dep].x + dx[i] * j] = 1;
		}

		dfs(dep + 1,core+1,wire+d);

		for (int j = 0; j < d; j++) {
			visit[v[dep].y + dy[i] * j][v[dep].x + dx[i] * j] = 0;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; i++) {
			map[i][0] = map[i][n + 1] = map[0][i] = map[n + 1][i] = -1;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) {
					if (i == 1 || i == n || j == 1 || j == n)e++;
					else v.push_back({ j,i });
				}
			}
		dfs(0,0,0);
		printf("#%d %d\n", tc, len);

		v.clear();
		memset(map, 0, sizeof(map));
		ans = 0; len = 987654321;
	}
	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//int n, T, map[15][15], maxCore = 0, minlen = 1000000, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool visit[15][15];
//struct point { int x, y, d; };
//vector<point> v, trace;
//bool safe(int x, int y) {
//	return x > 0 && x <= n && y > 0 && y <= n;
//}
//void func(int core, int line, int dep) {
//	if (dep == v.size()) {
//		if (core > maxCore) {
//			maxCore = core;
//			minlen = line;
//		}
//		else if (core == maxCore && line < minlen) {
//			minlen = line;
//		}
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		v[dep].d = i;
//		point t = v[dep];
//		int count = 0;
//
//		do {
//			t.x += dx[t.d];
//			t.y += dy[t.d];
//			if (map[t.y][t.x] || visit[t.y][t.x])break;
//			line++; visit[t.y][t.x] = 1; count++;
//			trace.push_back({ t.x,t.y });
//		} while (safe(t.x, t.y));
//
//		if (map[t.y][t.x] == 2)
//			func(core + 1, line, dep + 1);
//
//		line -= count;
//		while (count--) {
//			visit[trace.back().y][trace.back().x] = 0;
//			trace.pop_back();
//		}
//
//	}
//	func(core, line, dep + 1);
//}
//point cur; 
//int main() {
//	//freopen("input.txt", "r", stdin);
//	scanf("%d", &T);
//	for (int a = 1; a <= T; a++) {
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++) {
//				scanf("%d", &map[i][j]);
//			}
//		for (int i = 2; i < n; i++)
//			for (int j = 2; j < n; j++)if (map[i][j])v.push_back({ j,i });
//		for (int i = 0; i <= n + 1; i++) {
//			map[0][i] = 2;
//			map[i][0] = 2;
//			map[n + 1][i] = 2;
//			map[i][n + 1] = 2;
//		}
//		func(0,0,0);
//		printf("#%d %d\n", a, minlen);
//
//		memset(map, 0, sizeof(map));
//		v.clear(); maxCore = 0, minlen = 1000000;
//	}
//	return 0;
//}