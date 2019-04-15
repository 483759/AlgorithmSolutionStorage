#include <cstdio>
#include <queue>
using namespace std;
int T, M, N, K, dx[4] = { 1, -1, 0, 0 }, dy[4] = {0, 0, 1, -1}, cnt;
bool arr[51][51], visit[51][51];
struct p { int x, y; };
queue<p> q;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void bfs() {
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx= cur.x + dx[i], ty=cur.y + dy[i];
			if (arr[ty][tx] && !visit[ty][tx] && safe(tx, ty)) {
				visit[cur.y][cur.x] = true;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int a = 0; a < T; a++) {
		for (int i = 0; i<M; i++)
			for (int j = 0; j < N; j++) {
				arr[j][i] = false;
				visit[j][i] = false;
			}
		cnt = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0, x, y; i < K; i++) {
			scanf("%d%d", &x, &y);
			arr[y][x] = true;
		}

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++) {
				if (arr[j][i] && !visit[j][i]) {
					q.push({ i, j });
					visit[j][i] = true; 
					bfs();
					cnt++;
				}
			}

		printf("%d\n", cnt);
	}
}