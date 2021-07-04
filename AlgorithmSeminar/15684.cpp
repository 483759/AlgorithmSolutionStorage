#include <cstdio>
int n, m, h, ans = -1;
bool lad[35][15];

bool game() {
	for (int j = 1; j <= n; j++) {
		int cur = j;
		int row = 1;
		while (row <= h) {
			if (lad[row][cur])cur++;
			else if (lad[row][cur - 1])cur--;
			row++;
		}
		if (cur != j)return false;
	}
	return true;
}

void dfs(int r, int c, int k, int l) {
	if (ans != -1)return;
	if (c > n) {
		dfs(r + 1, 1, k, l);
		return;
	}
	if (r > h || !k) {
		if (game())ans = l - k;
		return;
	}

	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= h; i++) {
			if (lad[i][j] || lad[i][j - 1] || lad[i][j + 1])continue;
			lad[i][j] = 1;
			dfs(i, j + 1, k - 1, l);
			lad[i][j] = 0;
			while (lad[i][j - 1] || lad[i][j + 1])i++;
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		lad[a][b] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		dfs(1, 1, i, i);
	}
	printf("%d", ans != -1 ? ans : -1);
	return 0;
}


//#include <cstdio>
//int n, m, h, ans = 5;
//bool map[31][11];
//bool ladder() {
//	for (int j = 1; j <= n; j++) {
//		int cur = j;
//		for (int i = 1; i <= h; i++) {
//			if (cur && map[i][cur - 1])cur--;
//			else if (map[i][cur])cur++;
//		}
//		if (cur != j)return false;
//	}
//	return true;
//}
//void dfs(int dep, int k) {
//	if (ans != 5)return;
//	if (dep > k) {
//		if (ladder())ans = k;
//		return;
//	}
//	for (int j = 1; j < n; j++)
//		for (int i = 1; i <= h; i++) {
//			if (map[i][j] || map[i][j - 1] || map[i][j + 1]) continue;
//			map[i][j] = 1;
//			dfs(dep + 1, k);
//			map[i][j] = 0;
//			while (i < h) {
//				if (map[i][j - 1] || map[i][j + 1])break;
//				i++;
//			}
//		}
//	return;
//}
//int main() {
//	scanf("%d%d%d", &n, &m, &h);
//	for (int j = 0, a, b; j < m; j++) {
//		scanf("%d%d", &a, &b);
//		map[a][b] = 1;
//	}
//	for (int i = 0; i < 4; i++) {
//		dfs(1, i);
//		if (ans != 5) {
//			printf("%d", ans);
//			return 0;
//		}
//	}
//	printf("-1");
//	return 0;
//}