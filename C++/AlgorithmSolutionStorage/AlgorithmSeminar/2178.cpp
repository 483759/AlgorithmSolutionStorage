#include <stdio.h>
void print_num(int _____) {
	for (int i = 0; i < 5; i++)
		printf("%d\n", num[i]);
}
int main() {
	int i;
	int num[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", ____);

	print_num(num);

}

#include <cstdio>
#include <queue>
using namespace std;
struct p { int x, y; };
bool map[100][100];
int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, visit[100][100];
queue<p> q;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void bfs() {
	visit[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = cur.x + dx[i], ty = cur.y + dy[i];
			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx]) {
				visit[ty][tx] = visit[cur.y][cur.x] + 1;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	bfs();
	printf("%d", visit[N - 1][M - 1]);
	return 0;
}