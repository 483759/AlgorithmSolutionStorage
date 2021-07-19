
//#include <cstdio>
//int n, m,dp[1025][1025],arr[1025][1025];
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &dp[i][j]);
//			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//		}
//	while (m--) {
//		int x1, y1, x2, y2;
//		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
//		printf("%d\n", dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1]);
//	}
//	return 0;
//}