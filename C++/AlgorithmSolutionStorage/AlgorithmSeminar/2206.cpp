#include <cstdio>
#include <queue>
#define INF 987654321
using namespace std;
typedef struct { int x, y, b; }point;
int n, m, ans = INF, visit[2][1001][1001], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool map[1001][1001];
bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
void bfs() {
	queue<point> q;
	visit[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		if (cur.x == m - 1 && cur.y == n - 1)
			if (visit[cur.b][cur.y][cur.x] < ans) {
				ans = visit[cur.b][cur.y][cur.x];
				continue;
			}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			/*if (nx == m - 1 && ny == n - 1) {
				if (visit[cur.b][cur.y][cur.x] >= ans)
					ans = visit[cur.b][cur.y][cur.x] + 1;
				continue;
			}*/
			if (!safe(nx, ny))continue;
			if (cur.b) {
				if (visit[0][ny][nx]!=INF||visit[1][ny][nx]==visit[1][cur.y][cur.x]+1)continue;
				else if (!map[ny][nx] && (visit[1][ny][nx] > visit[1][cur.y][cur.x])) {
					visit[1][ny][nx] = visit[1][cur.y][cur.x] + 1;
					q.push({ nx,ny,1 });
				}
			}
			else {	//부신 적이 없을 때
				if (map[ny][nx]) {
					visit[1][ny][nx] = visit[0][cur.y][cur.x] + 1;
					q.push({ nx,ny,1 });
				}
				else if (!map[ny][nx]&&(visit[0][ny][nx]==INF)) {
					visit[0][ny][nx] = visit[0][cur.y][cur.x] + 1;
					q.push({ nx,ny,0 });
				}
			}
			//if (!safe(nx, ny) || visit[ny][nx]<=visit[cur.y][cur.x])continue;
			//if (map[ny][nx] && cur.b) {
			//	visit[ny][nx] = visit[cur.y][cur.x] + 1;
			//	q.push({ nx,ny,0 });
			//}
			//else if (!map[ny][nx]) {
			//	visit[ny][nx] = visit[cur.y][cur.x] + 1;
			//	q.push({ nx,ny,cur.b });
			//}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++) {
		scanf("%1d", &map[i][j]);
		visit[0][i][j] =visit[1][i][j]= INF;
	}
	bfs();
	//for(int k=0;k<2;k++)
	//for (int i = 0; i < n; i++)	{
	//	for (int j = 0; j < m; j++)printf("%4d", visit[k][i][j] == INF ? -1 : visit[k][i][j]);
	//	printf("\n");
	//}
	printf("%d", ans==INF?-1:ans);
	return 0;
}
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <memory.h>
//using namespace std;
//struct point { int x, y; };
//int n, m, map[1001][1001], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//int visit[1001][1001],ans=10000000;
//vector<point> v;
//queue<point> q;
//bool safe(int x, int y) {
//	return x >= 0 && x < m && y >= 0 && y < n;
//}
//void bfs(point p) {
//	map[p.y][p.x] = 0;
//
//	visit[0][0] = 1;
//	q.push({0,0});
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		for (int i = 0,tx,ty; i < 4; i++) {
//			tx = cur.x + dx[i], ty = cur.y + dy[i];
//			if (visit[ty][tx] > ans)break;
//			if (safe(tx, ty) && !map[ty][tx] && !visit[ty][tx]) {
//				visit[ty][tx] = visit[cur.y][cur.x]+1;
//				q.push({ tx,ty });
//			}
//			if (tx == m - 1 && ty == n - 1) {
//				ans = visit[ty][tx] < ans ? visit[ty][tx]:ans;
//				break;
//			}
//		}
//	}
//
//	memset(visit, 0, sizeof(visit));
//	map[p.y][p.x] = 1;
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			scanf("%1d", &map[i][j]);
//			if (map[i][j])v.push_back({ j,i });
//		}
//	for (point p : v)
//		bfs(p);
//	printf("%d", ans== 10000000?-1:ans);
//	return 0;
//}