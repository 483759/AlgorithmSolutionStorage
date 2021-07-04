#include <bits/stdc++.h>

int n,m;
int dp[3][41],vip[41];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,k; i < m; i++) {
		scanf("%d", &k);
		vip[k] = 1;
	}
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		if (vip[i]) {
			dp[1][i] = dp[1][i - 1];
		}
		else {
			dp[0][i] = dp[0][i - 1] + dp[2][i - 1];
			dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
			dp[2][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
		}
	}
	printf("%d", dp[0][n] + dp[1][n] + dp[2][n]);
	return 0;
}