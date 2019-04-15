#include <cstdio>
#include <queue>
using namespace std;

struct p { int x, y; };
int map[1001][1001], visit[1001][1001], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int N, M, mx = 1, zero;

queue<p> q;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void bfs() {
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = cur.x + dx[i]; ty = cur.y + dy[i];	//다음 탐색 노드 위치
			if (safe(tx, ty) && !map[ty][tx] && !visit[ty][tx]) {
				zero--;
				visit[ty][tx] = visit[cur.y][cur.x] + 1;
				mx = visit[ty][tx] > mx ? visit[ty][tx] : mx;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &M, &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ j, i });
				visit[i][j] = 1;
			}
			if (!map[i][j])	zero++;
		}

	bfs();

	if (zero) printf("-1");
	else printf("%d", mx - 1);
	return 0;
}