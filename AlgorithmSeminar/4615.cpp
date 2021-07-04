#include <cstdio>
int n, m,arr[105][105],ans;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > arr[i][j - 1])sum += arr[i][j] - arr[i][j - 1];
		}
		ans += sum;
	}

	for (int j = 1; j <= m; j++) {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			if (arr[i][j] > arr[i-1][j])sum += arr[i][j] - arr[i-1][j];

		ans += sum;
	}

	ans += n * m;
	printf("%d", ans*2);
	return 0;
}
//#include <cstdio>
//int T,n,m,map[10][10],ans[3];
//int dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
//bool safe(int x, int y) {
//	return x > 0 && x <= n && y > 0 && y <= n;
//}
//void flip(int x, int y, int dir,int color) {
//	int nx = x + dx[dir], ny = y + dy[dir];
//	while (safe(nx, ny) && map[ny][nx]&&map[ny][nx] != color) {
//		nx += dx[dir]; ny += dy[dir];
//	}
//	if (!map[ny][nx])return;
//	while (!(x == nx && y == ny)) {
//		map[y][x] = color;
//		x += dx[dir]; y += dy[dir];
//	}
//}
//void print() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &T);
//	for (int tc = 1; tc <= T; tc++) {
//		scanf("%d%d", &n, &m);
//		map[n/2][n/2] = map[n/2 + 1][n/2 + 1] = 2;
//		map[n / 2 + 1][n / 2] = map[n / 2][n / 2 + 1] = 1;
//		//print();
//
//		while (m--) {
//			int x, y, c;
//			scanf("%d%d%d", &x, &y, &c);
//
//			for (int i = 0; i < 8; i++)
//				flip(x, y, i, c);
//			print();
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				if (map[i][j])
//					ans[map[i][j]]++;
//		}
//		printf("#%d %d %d\n", tc, ans[1], ans[2]);
//		ans[1] = ans[2] = 0;
//	}
//	return 0;
//}