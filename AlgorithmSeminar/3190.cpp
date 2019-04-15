#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
struct point { int r, c; };
int n, k, l, t, sd, idx;
int map[101][101] = { 1 }, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
queue<point> snake;
pair<int, int> p[101];
bool safe(int r, int c) {
	return r > 0 && r <= n && c > 0 && c <= n;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0, r, c; i < k; i++) {
		scanf("%d %d", &r, &c);
		map[r][c] = 2;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		char c;
		scanf(" %d %c", &p[i].first, &c);
		if (c == 'D')p[i].second = 1;
		else p[i].second = -1;
	}
	map[1][1] = 1;
	snake.push({ 1, 1 });
	while (safe(snake.back().r, snake.back().c)) {
		t++;
		int sr = snake.back().r, sc = snake.back().c;

		//방향전환을 해야한다면
		if (t == p[idx].first + 1) {
			sd = (sd + p[idx++].second + 4) % 4;
		}

		sr += dy[sd]; sc += dx[sd];

		//이동할 칸에 사과가 잇다면 사과를 머리로 대체
		if (map[sr][sc] == 2) {
			map[sr][sc] = 1;
			snake.push({ sr, sc });
		}
		else if (map[sr][sc] == 1)break;
		//이동할 칸에 사과가 없다면 꼬리를 없앤다
		else {
			map[sr][sc] = 1;	//머리를 옮긴다
			snake.push({ sr, sc });
			map[snake.front().r][snake.front().c] = 0;
			snake.pop();
		}
		//sr += dy[sd]; sc += dx[sd];	//다음 위치를 계산

		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= n; j++)
		//		printf("%d ", map[i][j]);
		//	printf("\n");
		//}
		//printf("\n");

	}
	printf("%d", t);
	return 0;
}