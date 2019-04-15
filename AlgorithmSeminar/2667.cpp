#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct p { int x, y; };
queue<p> q;
bool map[26][26], visit[26][26];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, num[300];
int N, cnt, index;
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
int bfs() {
	int hnum = 1;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int next = 0, tx, ty; next < 4; next++) {
			tx = cur.x + dx[next], ty = cur.y + dy[next];
			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx]) {
				visit[ty][tx] = true;
				q.push({ tx, ty });
				hnum++;
			}
		}
	}
	return hnum;
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visit[i][j]) {
				q.push({ j, i });
				visit[i][j] = true;
				num[cnt]=bfs();
				cnt++;
			}
		}
	sort(num, num + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d\n", num[i]);
	return 0;
}