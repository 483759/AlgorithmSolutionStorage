#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef struct { int x, y, m, d; }gun;
int tc, n, m, k;
int map[105][105], dx[] = { 0,0,0,-1,1 }, dy[] = { 0,-1,1,0,0 }, nd[] = {0,2,1,4,3};
bool safe(int x, int y) {
	return x > 0 && x < n - 1 && y>0 && y < n - 1;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		int ans = 0; memset(map, 0, sizeof(map));
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			map[0][i] = -1;
			map[i][0] = -1;
			map[i][n - 1] = -1;
			map[n - 1][i] = -1;
		}
		queue<gun> q;
		for (int i = 0; i < k; i++) {
			int x, y, s, d;
			scanf("%d%d%d%d", &y, &x, &s, &d);
			q.push({ x,y,s,d });
			map[y][x] = 1;
		}
		while (m--) {
			for (int i = q.size(); i > 0; i--) {
				gun cur = q.front(); q.pop();
				map[cur.y][cur.x]--;
				int nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
				if (!safe(nx,ny)) {
					cur.x = nx; cur.y = ny; cur.d = nd[cur.d];
					cur.m /= 2;
					if (!cur.m)continue;
				}
				else {
					cur.x = nx; cur.y = ny;
					map[ny][nx]++;
				}
				q.push(cur);
			}

			for(int i=1;i<n-1;i++)
				for(int j=1;j<n-1;j++)
					if (map[i][j] > 1) {
						int sum = 0,max=0,d=0;
						for (int a = q.size(); a > 0; a--) {
							gun cur = q.front(); q.pop();
							if (!(cur.x == j && cur.y==i)) {
								q.push(cur);
								continue;
							} 
							sum += cur.m;
							if (cur.m > max) {
								max = cur.m;
								d = cur.d;
							}
						}
						map[i][j] = 1;
						q.push({ j,i,sum,d });
					}
		}
		while (!q.empty()) {
			ans += q.front().m; q.pop();
		}
		printf("#%d %d\n", T, ans);
	}
	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//typedef struct {
//	int c, d;
//}cell;
//int tc, n, m, k, ans, dx[] = { 0,0,0,-1,1 }, dy[] = { 0,-1,1,0,0 }, nd[] = {0,2,1,4,3};
//queue<cell> v[101][101];
//cell map[101][101], a = { 0,0 };
//void print() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			printf("%d ", map[i][j].c);
//		printf("\n");
//	}printf("\n");
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int T = 1; T <= tc; T++) {
//		ans = 0;
//		scanf("%d%d%d", &n, &m, &k);
//		for (int i = 0,x,y,c,d; i < k; i++) {
//			scanf("%d%d%d%d", &y, &x, &c, &d);
//			map[y][x]={c,d };
//		}
//		//print();
//
//		while (m--) {
//			for (int i = 0; i < n; i++)
//				for (int j = 0; j < n; j++) {
//					if (!map[i][j].c)continue;
//					int nx = j + dx[map[i][j].d],
//						ny = i + dy[map[i][j].d];
//					v[ny][nx].push(map[i][j]);
//				}
//			
//			fill(&map[0][0], &map[n][n - 1], a);
//
//			for(int i=0;i<n;i++)
//				for(int j=0;j<n;j++)
//					if (!(i > 0 && i < n - 1 && j>0 && j < n - 1)&&!v[i][j].empty()) {
//						map[i][j] = { v[i][j].front().c / 2,nd[v[i][j].front().d] };
//						v[i][j].pop();
//					}
//
//			for (int i = 1; i < n-1; i++)
//				for (int j = 1; j < n - 1; j++) {
//					if (v[i][j].size() > 1) {
//						int sum = 0,max=0,md=0;
//						while (!v[i][j].empty()) {
//							sum += v[i][j].front().c;
//							if (v[i][j].front().c > max) {
//								max = v[i][j].front().c;
//								md = v[i][j].front().d;
//							}
//							v[i][j].pop();
//						}
//						map[i][j] = { sum,md };
//					}
//					else if (v[i][j].size() == 1) {
//						map[i][j] = v[i][j].front();
//						v[i][j].pop();
//					}
//				}
//			//print();
//		}
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				ans += map[i][j].c;
//		printf("#%d %d\n", T, ans);
//		fill(&map[0][0], &map[n][n - 1], a);
//	}
//	return 0;
//}