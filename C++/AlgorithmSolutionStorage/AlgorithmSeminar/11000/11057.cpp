#include <cstdio>
int n, k, ans, dp[1001][10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)dp[1][i] = 1;
	for(int i=2;i<=n;i++)
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	for (int i = 0; i < 10; i++)ans += dp[n][i];
	printf("%d", ans % 10007);
	return 0;
}