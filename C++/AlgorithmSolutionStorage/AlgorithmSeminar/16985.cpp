#include <cstdio>
#include <algorithm>
int main() {
	int arr[5][5];
	std::fill(&arr[0][0], &arr[4][5], 7);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//using namespace std;
//int arr[5][4][5][5], rot[5], seq[5], ans = 987654321;	//회전/z/y/x
//int dx[] = { 1,-1,0,0,0 }, dy[] = { 0,0,1,-1,0 }, dz[] = { 0,0,0,0,1 };
//int crr[5][5][5], visit[5][5][5];
//bool num[5];
//typedef struct {
//	int x, y, z;
//}point;
//int cnt;
//queue<point> q;
//bool safe(int x, int y, int z) { return x >= 0 && x < 5 && y >= 0 && y < 5 && z >= 0 && z < 5; }
//int bfs() {
//	fill()
//	memset(visit, 0, sizeof(visit));
//	if (!crr[0][0][0])return -1;
//	q.push({ 0,0,0 });
//	visit[0][0][0] = 1;
//
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		for (int i = 0; i < 5; i++) {
//			int nx = cur.x + dx[i], ny = cur.y + dy[i], nz = cur.z + dz[i];
//			if (safe(nx, ny, nz) && crr[nz][ny][nx] && !visit[nz][ny][nx]) {
//				q.push({ nx,ny,nz });
//				visit[nz][ny][nx] = visit[cur.z][cur.y][cur.x] + 1;
//				if (nx * ny * nz == 64) {//도착이면
//					while (!q.empty())q.pop();
//					return visit[nz][ny][nx] - 1;
//				}
//			}
//		}
//	}
//	return -1;
//
//}
//void dfs2(int dep) {
//	if (dep == 5) {
//		for (int k = 0; k < 5; k++)
//			for (int i = 0; i < 5; i++)
//				for (int j = 0; j < 5; j++)
//					crr[k][i][j] = arr[seq[k]][rot[k]][i][j];
//
//		if (!crr[0][0][0] || !crr[4][4][4])return;
//		int dis = bfs();
//		if (dis > 0 && dis < ans)
//			ans = dis;
//
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		rot[dep] = i;
//		dfs2(dep + 1);
//	}
//}
//void dfs1(int dep) {
//	if (dep == 5) {
//		dfs2(0);
//		return;
//	}
//
//	for (int i = 0; i < 5; i++) {
//		if (num[i])continue;
//		seq[dep] = i; num[i] = 1;
//		dfs1(dep + 1);
//		num[i] = 0;
//	}
//}
//int main() {
//	for (int k = 0; k < 5; k++)
//		for (int i = 0; i < 5; i++)
//			for (int j = 0; j < 5; j++)
//				scanf("%d", &arr[k][0][i][j]);
//
//	for (int k = 0; k < 5; k++)
//		for (int d = 1; d < 4; d++)
//			for (int i = 0; i < 5; i++)
//				for (int j = 0; j < 5; j++)
//					arr[k][d][j][4 - i] = arr[k][d - 1][i][j];
//	dfs1(0);
//	printf("%d", ans == 987654321 ? -1 : ans);
//	return 0;
//}