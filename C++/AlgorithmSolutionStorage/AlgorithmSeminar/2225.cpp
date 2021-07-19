#include <cstdio>
int n, a[1001],dp[1001],ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j]<a[i] && dp[j] + 1>dp[i])
				dp[i] = dp[j] + 1;
	}
	for (int i = 0; i < n; i++)ans = dp[i] > ans ? dp[i] : ans;
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//int n, k,dp[201][201];
//int main() {
//	scanf("%d%d", &n, &k);
//	dp[0][0] = 1LL;
//	for (int i = 1; i <= k; i++) {
//		for(int j=0;j<=n;j++)
//			for (int l = 0; l < j; l++) {
//				dp[i][j] += dp[i - 1][j - l];
//				dp[i][j] %= 1000000000;
//			}
//	}
//	printf("%d", dp[k][n]);
//	return 0;
//}