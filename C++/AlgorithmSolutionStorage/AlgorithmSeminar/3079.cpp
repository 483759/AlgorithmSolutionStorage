#include <stdio.h>
char num[7], map[20][20];
char dx[] = { 0, 1, -1, 0, 0 }, dy[] = { 0, 0, 0, -1, 1 };
int main() {
	int w = 4, s = 5, on = 1, x, y, n, m, k, op, tmp;
	scanf("%d%d%d%d%d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < k; i++) {
		scanf("%d", &op);
		int nx = x + dx[op], ny = y + dy[op];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		x += dx[op]; y += dy[op];
		if (op % 2) {
			tmp = on;
			on = (op == 1) ? 7 - w : 7 - s;
			if (op == 1) w = tmp;
			else s = tmp;
		}
		else {
			tmp = (op == 2) ? w : s;
			if (op == 2)w = 7 - on;
			else s = 7 - on;
			on = tmp;
		}
		if (!map[y][x])
			map[y][x] = num[on];
		else {
			num[on] = map[y][x];
			map[y][x] = 0;
		}
		printf("%d\n", num[7 - on]);
	}
	return 0;
}
//#include <cstdio>
//#define ull unsigned long long
//int n, m, t[100005];
//ull ans, max,min=987654321;
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &t[i]);
//		if (t[i] > max)max = t[i];
//	}
//	ull left = 0, right = (ull)max*m;
//	ans = right;
//	while (left <= right) {
//		ull mid = (left + right) / 2;
//
//		ull sum = 0;
//		for (int i = 0; i < n; i++)sum += mid / t[i];
//
//		if (sum >= m) {
//			right = mid - 1;
//			if (mid < ans)ans = mid;
//		}
//		else left = mid + 1;
//	}
//	printf("%lld", ans);
//	return 0;
//}