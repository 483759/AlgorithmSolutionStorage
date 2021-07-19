#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef struct { int x, y; }point;
char map[12][7];
int visit[12][6], ans;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool safe(int x, int y) { return x >= 0 && x < 6 && y >= 0 && y < 12; }

int countConnectedPuyo(point p, int k) {
	visit[p.y][p.x] = k;

	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = p.x + dx[i], ny = p.y + dy[i];
		if (!safe(nx, ny) || map[ny][nx] != map[p.y][p.x] || visit[ny][nx])continue;
		cnt+= countConnectedPuyo({ nx,ny }, k);
	}
	return cnt;
}

void popPuyo(int k) {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			if (visit[i][j] == k)
				map[i][j] = '.';
}

void gravity() {
	queue<char> q;

	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] == '.')continue;
			q.push(map[i][j]);
			map[i][j] = '.';
		}
		int r = 11;
		while (!q.empty()) {
			map[r][j] = q.front(); q.pop();
			r--;
		}
	}
}

void printMap() {
	for (int i = 0; i < 12; i++)
		printf("%s\n", map[i]);
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 12; i++)
		scanf("%s", map[i]);

	while (++ans) {
		int k = 1, b = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.')continue;
				if (countConnectedPuyo({ j,i }, k) >= 4) {
					popPuyo(k);
					b = 1;
				}
				k++;
			}
		if (b)
			gravity();
		else break;
	}
	printf("%d", ans - 1);
	return 0;
}