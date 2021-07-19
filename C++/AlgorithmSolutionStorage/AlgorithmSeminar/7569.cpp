#include <cstdio>
#include <queue>
using namespace std;

typedef struct { int x, y, z; }point;
int n, m, h, ans, tomato, box[105][105][105];
int dx[] = { 1,0,-1,0,0,0 }, dy[] = { 0,1,0,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
bool visit[105][105][105];
queue<point> q;

bool safe(int x, int y, int z) { return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < h; }

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &m, &n, &h);
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &box[k][i][j]);
				if (!box[k][i][j])tomato++;
				else if (box[k][i][j] == 1) {
					q.push({ j,i,k });
					visit[k][i][j] = 1;
				}

			}

	if (!tomato) { printf("0"); return 0; }
	while (!q.empty() && ++ans) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			point cur = q.front(); q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i], nz = cur.z + dz[i];
				if (!safe(nx, ny, nz) || box[nz][ny][nx] == -1 || visit[nz][ny][nx])continue;
				visit[nz][ny][nx] = 1;
				q.push({ nx,ny,nz });
				tomato--;
			}
			if (!tomato) {
				printf("%d", ans);
				return 0;
			}
		}
	}
	printf("%d", tomato ? -1 : ans);
	return 0;
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//typedef struct { int x, y,z; }point;
//int n, m, h,ans,no;
//int dx[] = { 1,0,-1,0,0,0 }, dy[] = { 0,1,0,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
//int box[101][101][101],visit[101][101][101];
//queue<point> q;
//bool safe(int x, int y, int z) {
//	return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < h;
//}
//void bfs() {
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		for (int i = 0; i < 6; i++) {
//			int nx = cur.x + dx[i], ny = cur.y + dy[i], nz = cur.z + dz[i];
//
//			if (safe(nx, ny, nz) && !box[nz][ny][nx] && !visit[nz][ny][nx]) {
//				q.push({ nx,ny,nz });
//				visit[nz][ny][nx] = visit[cur.z][cur.y][cur.x] + 1;
//				no--;
//				if (visit[nz][ny][nx] > ans)ans = visit[nz][ny][nx];
//			}
//		}
//	}
//}
//int main() {
//	scanf("%d%d%d", &m, &n, &h);
//	for (int k = 0; k < h; k++)
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &box[k][i][j]);
//			if (!box[k][i][j])no++;
//			if (box[k][i][j] == 1) {
//				visit[k][i][j] = 1;
//				q.push({ j,i,k });
//			}
//			
//		}
//	if (!no) { printf("0"); return 0; }
//	bfs();
//	printf("%d", no ? -1 : ans-1);
//	return 0;
//}