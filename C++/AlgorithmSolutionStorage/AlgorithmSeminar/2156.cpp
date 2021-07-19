#include <cstdio>
int n, val[10001], dp[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &val[i]);
	dp[1] = val[1]; dp[2] = val[1] + val[2];
	for (int i = 3; i <= n; i++) {
		int a = dp[i - 1];
		int b = dp[i - 2] + val[i];
		int c = dp[i - 3] + val[i - 1] + val[i];
		dp[i] = (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
	}
	printf("%d", dp[n]);
	return 0;
}