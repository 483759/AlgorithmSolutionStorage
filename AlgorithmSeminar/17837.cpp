//#include <cstdio>
//#include <vector>
//#include <stack>
//using namespace std;
//typedef struct { int n,x, y, d; }point;
//vector<point> v;
//int map[13][13][4];
//int pan[13][13], dx[] = { 0,1,-1,0,0 }, dy[] = { 0,0,0,-1,1 }, nd[] = { 0,2,1,4,3 };
//int n, k, ans;
//bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
//		scanf("%d", &pan[i][j]);
//	v.push_back({ 0 });
//	for (int i = 1; i <= k; i++) {
//		int x, y, d;
//		scanf("%d%d%d", &y, &x, &d);
//		v.push_back({ i,x-1,y-1,d });
//		map[y - 1][x - 1][0] = i;
//	}
//	while (++ans<=1000) {
//		bool b = 1;
//		for (int i = 1; i < v.size(); i++) {
//			int cx = v[i].x, cy = v[i].y;
//			int nx = cx + dx[v[i].d], ny = cy + dy[v[i].d];
//			if (!safe(nx, ny) || pan[ny][nx] == 2) {
//				if (b) { b = 0;v[i].d = nd[v[i].d]; i--;}
//				else b = 1;
//			}
//			else if (!pan[ny][nx]) {
//				int cur = 0;
//				for (map[cy][cx][cur] != i; cur++;);
//				for (; cur < 4;) {
//					map[ny][nx].push_back(*it);
//					int num = *it;
//					it = map[cy][cx].erase(it);
//					v[num].x = nx; v[num].y = ny;
//				}
//				if (map[ny][nx].size() >= 4) {
//					printf("%d", ans); return 0;
//				}
//				else b = 1;
//			}
//			else {
//				while (1) {
//					int p = map[cy][cx].back();
//					map[cy][cx].pop_back();
//					map[ny][nx].push_back(p);
//					v[p].x = nx; v[p].y = ny;
//					if (p == v[i].n)break;
//				}
//				if (map[ny][nx].size() >= 4) {
//					printf("%d", ans); return 0;
//				}
//				else b = 1;
//			}
//		}
//	}
//	printf("-1");
//	return 0;
//}