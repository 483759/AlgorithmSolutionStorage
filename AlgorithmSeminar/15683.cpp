#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct {
	int x, y;
}point;
int n, x, y;
point p[100001];
bool cmp(point a, point b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);
	return 0;
}
//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
//int n, m, ans = 100, map[9][9], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//typedef struct {
//	int tv, x, y;
//}point; 
//vector<point> v;
//bool safe(int x, int y) {
//	return x >= 0 && x < m && y >= 0 && y < n;
//}
//void monitor(int x,int y, int dir) {
//	int nx = x + dx[dir], ny=y + dy[dir] ;
//	while (safe(nx,ny)&&map[ny][nx]!=6) {
//		map[ny][nx] = 7;
//		nx += dx[dir]; ny += dy[dir];
//	}
//}
//void func(int dep) {
//	if (dep == (int)v.size()) {
//		int sum = 0;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				if (!map[i][j])
//					sum++;
//		if (sum < ans)ans = sum;
//		return;
//	}
//	int tmp[9][9];
//	memcpy(tmp, map, sizeof(map));
//	for (int i = 0; i < 4; i++) {
//		int cx = v[dep].x, cy = v[dep].y;
//		switch (v[dep].tv) {
//		case 1:
//			monitor(cx, cy, i);
//			break;
//		case 2:
//			if (i < 2) {
//				monitor(cx, cy, i);
//				monitor(cx, cy, i+2);
//			}
//			break;
//		case 3:
//			monitor(cx, cy, i);
//			monitor(cx, cy, (i+1)%4);
//			break;
//		case 4:
//			monitor(cx, cy, i);
//			monitor(cx, cy, (i + 1) % 4);
//			monitor(cx, cy, (i + 2) % 4);
//			break;
//		case 5:
//			if (!i) {
//				monitor(cx, cy, 0);
//				monitor(cx, cy, 1);
//				monitor(cx, cy, 2);
//				monitor(cx, cy, 3);
//			}
//
//		}
//		func(dep + 1);
//		memcpy(map, tmp, sizeof(map));
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &map[i][j]);
//			if (map[i][j] && map[i][j] < 6)
//				v.push_back({ map[i][j], j,i });
//		}
//	func(0);
//	printf("%d", ans);
//	return 0;
//}