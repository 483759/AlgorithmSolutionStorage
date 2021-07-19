#include <cstdio>
#include <queue>
using namespace std;

typedef struct { int x, y; }point;
typedef struct { int x, y, s; }fish;
int n, ans,feed,map[21][21], dx[] = { 0,-1,1,0 }, dy[] = {-1,0,0,1};
fish shark;

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				shark.x = j; shark.y = i;
				map[i][j] = 0;
			}
		}
	shark.s = 2;

	while (1) {
		queue<point> q;
		bool visit[21][21] = { 0 };

		q.push({ shark.x,shark.y });
		visit[shark.y][shark.x] = 1;

		bool b = false;
		int dist = 987654321;
		point f = { n,n };
		int time = 0;
		while (!q.empty()&&!b) {
			int size = q.size();
			for (int i=0; i < size; i++) {
				point cur = q.front(); q.pop();

				if (time<=dist&&map[cur.y][cur.x] && map[cur.y][cur.x] < shark.s) {
					if (cur.y < f.y || (cur.y == f.y && cur.x < f.x)) {
						f = cur;
						dist = time;
					}
				}
				for (int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i], ny = cur.y + dy[i];
					if (safe(nx, ny) && map[ny][nx] <= shark.s && !visit[ny][nx]) {
						q.push({ nx,ny });
						visit[ny][nx] = 1;
					}
				}
			}
			time++;
		}



		if (f.x == n) {
			break;
		}
		else {
			map[f.y][f.x] = 0;
			shark = { f.x,f.y,shark.s };
			feed++;
			if (feed == shark.s) {
				feed = 0;
				shark.s++;
			}
			ans += dist;
		}


		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++)
		//		printf("%d ", map[i][j]);
		//	printf("\n");
		//}
		//printf("\n");
	}
	printf("%d", ans);
	return 0;
}




//#include <cstdio>
//#include <cstring>
//#include <queue>
//using namespace std;
//int n, m, w = 2, sum, ans, map[21][21], dx[] = { 0,-1,0,1 }, dy[] = { -1,0,1,0 };
//bool visit[21][21];
//typedef struct {
//	int r, c, d;
//}point;
//point shark,fish;
//queue<point> q;
//bool safe(int r, int c) {
//	return r >= 0 && r < n && c >= 0 && c < n;
//}
//point bfs() {
//	memset(visit, false, sizeof(visit));
//	point r = { 21,21,1000 };
//	q.push(shark);
//	visit[shark.r][shark.c] = 1;
//
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		for (int k = 0, nr, nc; k < 4; k++) {
//			nr = cur.r + dy[k], nc = cur.c + dx[k];
//			if (safe(nr, nc) && map[nr][nc] <= w && !visit[nr][nc]) {
//				q.push({ nr,nc,cur.d + 1 });
//				visit[nr][nc] = 1;
//				if (map[nr][nc] < w && map[nr][nc])
//					if ((cur.d + 1 < r.d)
//						|| (cur.d + 1 == r.d && nr < r.r)
//						|| (cur.d + 1 == r.d && nr == r.r && nc < r.c))
//					r = { nr,nc,cur.d + 1 };
//			}
//		}
//	}
//	return r;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &map[i][j]);
//			if (map[i][j] == 9)
//				shark = { i,j,0 };
//		}
//
//	while (1) {
//		fish = bfs();
//		//∏‘¿ª ºˆ ¿÷¥¬ π∞∞Ì±‚ ≈Ωªˆ
//		if (fish.r * fish.c * fish.d > 440000) {
//			printf("%d", ans);
//			return 0;
//		}
//
//		ans += fish.d;
//		map[shark.r][shark.c] = 0;
//		shark = {fish.r,fish.c,0};
//		map[shark.r][shark.c] = 9;
//
//		if (++sum == w) {
//			w++;
//			sum = 0;
//		}
//		//π∞∞Ì±‚ ∏‘¿Ω
//	}
//	return 0;
//}