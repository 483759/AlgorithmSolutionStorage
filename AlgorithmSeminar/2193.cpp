#include <cstdio>
int n, m, cnt;
long long max, val[100001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		val[i] += val[i - 1];
		if (i < m - 1)continue;
		val[i] -= val[i - m];
		max = val[i] > max ? val[i] : max;
	}
	printf("%lld", max);
	return 0;
}
//#include <cstdio>
//int n;
//long long dp[91][2];
//int main() {
//	dp[1][1] = 1;
//	scanf("%d", &n);
//	for (int i = 2; i <= n; i++) {
//		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
//		dp[i][1] = dp[i - 1][0];
//	}
//	printf("%lld", dp[n][0] + dp[n][1]);
//	return 0;
//}