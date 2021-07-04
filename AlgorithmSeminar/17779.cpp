#include <cstdio>
int n, map[25][25],sum, ans = 987654321;
int g[25][25];
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%2d", g[i][j]);
		printf("\n");
	}
}
int mand(int x, int y, int d1, int d2) {
	for (int k = 0; k <= d1; k++) {
		g[x + k][y - k] = 5;
		g[x + d2 + k][y + d2 - k] = 5;
	}
	for (int k = 0; k <= d2; k++) {
		g[x + k][y + k] = 5;
		g[x + d1 + k][y - d1 + k] = 5;
	}
	for (int i = 1; i < x + d1; i++) {
		int num = 1;
		for (int j = 1; j <= y; j++) {
			if (g[i][j] == 5)num = 5;
			g[i][j] = num;
		}
	}
	for (int i = 1; i <= x + d2; i++) {
		int num = 2;
		for (int j = n; j > y; j--) {
			if (g[i][j] == 5)num = 5;
			g[i][j] = num;
		}
	}
	for (int i = x + d1; i <= n; i++) {
		int num = 3;
		for (int j = 1; j <= y - d1 + d2; j++) {
			if (g[i][j] == 5)num = 5;
			g[i][j] = num;
		}
	}
	for (int i = x + d2 + 1; i <= n; i++) {
		int num = 4;
		for (int j = n; j >= y - d1 + d2; j--) {
			if (g[i][j] == 5)num = 5;
			g[i][j] = num;
		}
	}
	int p[6] = { 0 }, min = 987654321, max = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			p[g[i][j]] += map[i][j];
			g[i][j] = 0;
		}
	for (int i = 1; i < 6; i++) {
		if (p[i] < min)min = p[i];
		if (p[i] > max)max = p[i];
		p[i] = 0;
	}
	return max - min;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)
		scanf("%d", &map[i][j]);
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			for (int d1 = 1; d1 < n; d1++)
				for (int d2 = 1; d2 < n; d2++) {
					if ((x + d1 + d2 > n) || (y - d1 < 1) || (y + d2 > n))continue;
					int k = mand(x, y, d1, d2);
					if (k < ans)ans = k;
				}
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//int n, map[21][21], arr[21][21], sum, ans=1000000;
//bool safe(int r, int c) {
//	return r >= 1 && r <= n && c >= 1 && c <= n;
//}
//void func(int row, int col, int d1, int d2) {
//	int p[6] = { 0 };
//
//	for (int i = 0; i <= d1; i++)
//		map[row + i][col - i] = 5;
//	for (int i = 0; i <= d2; i++)
//		map[row + i][col + i] = 5;
//	for (int i = 0; i <= d2; i++)
//		map[row + d1 + i][col - d1 + i] = 5;
//	for (int i = 0; i <= d1; i++)
//		map[row + d2 + i][col + d2 - i] = 5;
//
//	for (int i = 1; i < row + d1; i++)
//		for (int j = 1; j <= col; j++) {
//			if (map[i][j] == 5)break;
//			map[i][j] = 1;
//			p[1] += arr[i][j];
//		}
//	for (int i = 1; i <= row + d2; i++)
//		for (int j = n; j > col; j--) {
//			if (map[i][j] == 5)break;
//			map[i][j] = 2;
//			p[2] += arr[i][j];
//		}
//	for (int i = row+d1; i <= n; i++)
//		for (int j = 1; j < col-d1+d2; j++) {
//			if (map[i][j] == 5)break;
//			map[i][j] = 3;
//			p[3] += arr[i][j];
//		}
//	for (int i = row + d2+1; i <= n; i++)
//		for (int j = n; j >= col - d1 + d2; j--) {
//			if (map[i][j] == 5)break;
//			map[i][j] = 4;
//			p[4] += arr[i][j];
//		}
//
//	p[5] = sum;
//	for (int i = 1; i <= 4; i++)p[5] -= p[i];
//
//	std::sort(p + 1, p + 6);
//
//	if (p[5] - p[1] < ans)ans = p[5] - p[1];
//	memset(map, 0, sizeof(map));
//	return;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &arr[i][j]);
//			sum += arr[i][j];
//		}
//
//	for (int row = 1; row <= n; row++)
//		for (int col = 1; col <= n; col++)
//			for (int d1 = 1; d1 <= n; d1++)
//				for (int d2 = 1; d2 <= n; d2++) {
//					if ((row + d1 + d2 > n) || (col - d1 < 1) || (col + d2) > n)continue;
//					func(row, col, d1, d2);
//				}
//
//	printf("%d", ans);
//	return 0;
//}