#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
int T, N, M, R, C, L, tnl[51][51];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
bool pip[8][4] = {
	{0,0,0,0},	{1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0}
}, visit[51][51];
typedef struct {
	int x, y, d, t;
}point;
queue<point> q;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
bool connect(int nx, int ny, int cdir) {
	int ndir = cdir <= 1 ? ((cdir + 1) % 2) : ((cdir - 1) % 2 + 2);
	return pip[tnl[ny][nx]][ndir];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	int tc = T;
	while (T--) {
		int ans = 0;
		scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);		
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)scanf("%d", &tnl[i][j]);

		q.push({ C,R,tnl[R][C],1 });
		visit[R][C] = true;
		while (!q.empty()) {
			point cur = q.front(); q.pop();
			if (cur.t >= L)continue;
			//pip[3] pip[tnl[ny][nx]] i 01 10 23 32
			for (int i = 0,nx,ny; i < 4; i++) {
				nx = cur.x + dx[i], ny = cur.y + dy[i];
				if (pip[cur.d][i] && connect(nx, ny, i)
					&& safe(nx, ny) && !visit[ny][nx]) {
					q.push({ nx,ny,tnl[ny][nx],cur.t + 1 });
					visit[ny][nx]=true;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (visit[i][j]) {
					ans++; //printf("1 ");
				}
				//else printf("0 ");
			//printf("\n");
		}

		printf("#%d %d\n",tc-T,ans);
	}

	return 0;
}