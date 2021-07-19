#include <cstdio>
int map[19][19], dx[] = { 1,1,1,0 }, dy[] = { -1,0,1,1 };
int n;
bool safe(int x, int y) { return x >= 0 && x < 19 && y >= 0 && y < 19; }
bool func(int x, int y, int d, int c) {
	int sum = 0, max = 0;
	if (safe(x - dx[d], y - dy[d]) && map[y - dy[d]][x - dx[d]] == c)return 0;
	while (safe(x, y)) {
		if (map[y][x] == c)sum++;
		else {
			return sum == 5;
		}
		x += dx[d], y += dy[d];
	}
	return sum == 5;
}
bool count() {
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++) {
			if (map[i][j] ==0)continue;
			for (int k = 0; k < 4; k++) {

				if (func(j, i, k, map[i][j])) {
					printf("%d\n%d %d", map[i][j], i + 1, j + 1);
					return 1;
				}
			}
		}
	return 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	for(int i=0;i<19;i++)
		for (int j = 0; j < 19; j++) {
			scanf("%d", &map[i][j]);
		}
	if (!count())printf("0");
	return 0;
}

//#include <cstdio>
//char map[10005][10005];
//int n, m, ans;
//bool pipe(int r,int c) {
//	if (map[r][c]!='.')return false;
//	if (c == m-1) return true;
//	map[r][c] = 'x';
//	return pipe(r - 1, c + 1) || pipe(r, c + 1) || pipe(r + 1, c + 1);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		scanf(" %s", map[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		if (pipe(i, 0))ans++;
//	}
//	printf("%d", ans);
//	return 0;
//}