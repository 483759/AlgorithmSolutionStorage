#include <cstdio>
#include <queue>
#define loc 250
using namespace std;
int tc, ans, n, m, k, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
typedef struct {
	int r, c;
}point;
typedef struct {
	int state, X, cnt;
}cell;
cell map[501][501];
bool visit[501][501];
queue<point> A, N,W;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = loc; i < loc + n; i++)
			for (int j = loc, d; j < loc + m; j++) {
				scanf("%d", &d);
				if (d) {
					map[i][j] = {3,d,d};
					N.push({ i,j });
				}
			}

		while (k--) {	//K초동안
			//활성세포 처리
			int nonActsize = N.size();
			for (int i = (int)A.size(); i >0 ; i--) {
				point cp = A.front(); A.pop();
				cell& cur = map[cp.r][cp.c];
				if (cur.cnt == cur.X)
					for (int d = 0, nx, ny; d < 4; d++) {
						ny = cp.r + dy[d], nx = cp.c + dx[d];
						if (!map[ny][nx].state
							|| (map[ny][nx].state == 4
								&& map[ny][nx].X < cur.X)) {
							map[ny][nx] = {4,cur.X,cur.X};
							if (!visit[ny][nx]) {
								W.push({ ny,nx });
								visit[ny][nx] = 1;
							}
						}
					}//4방향 번식
				cur.cnt--;	//생명력 감소
				if (!cur.cnt)	//사망
					cur.state = 1;
				else A.push(cp);
			}
			while (!W.empty()) {
				point cp = W.front(); W.pop();
				cell& cur = map[cp.r][cp.c];
				visit[cp.r][cp.c] = 0;
				cur.state = 3;
				N.push(cp);
			}

			for (int i = nonActsize; i >0 ; i--) {
				point cp = N.front(); N.pop();
				cell& cur = map[cp.r][cp.c];;
				if (!(--cur.cnt)) {
					cur.state = 2;
					cur.cnt = cur.X;
					A.push(cp);
				}
				else
					N.push(cp);
			}
		}
		ans = A.size() + N.size();

		printf("#%d %d\n", T, ans); ans = 0;
		while (!A.empty())A.pop();
		while (!N.empty())N.pop();
		for(int i=0;i< 500;i++)
			for(int j=0;j< 500;j++)
				if (map[i][j].state) {
					map[i][j] = { 0,0,0 };
				}

	}
	return 0;
}