#include <cstdio>
#define max(a,b) a>b?a:b
int n, t, val[2][100001], dp[2][100001];
int main() {
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++)
			for (int i = 1; i <= n; i++)scanf("%d", &val[j][i]);
		dp[0][1] = val[0][1]; dp[1][1] = val[1][1];
		for (int i = 2, temp; i <= n; i++) {
			temp = max(dp[0][i - 2], dp[1][i - 2]);
			dp[0][i] = val[0][i] + max(temp, dp[1][i - 1]);
			dp[1][i] = val[1][i] + max(dp[0][i - 1], temp);
		}
		printf("%d\n", max(dp[0][n], dp[1][n]));
	}
	return 0;
}