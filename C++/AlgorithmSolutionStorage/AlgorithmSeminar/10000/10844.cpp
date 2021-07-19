#include <cstdio>
#define mod 1000000000
int n, dp[10][101];
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)dp[i][1] = 1;
	for(int j=2;j<=n;j++)
	for (int i = 0; i < 10; i++) {
		if (i > 0)dp[i][j] += dp[i - 1][j - 1];
		if (i < 9)dp[i][j] += dp[i + 1][j - 1];
		dp[i][j] %= mod;
	}
	for (int i = 0; i < 10; i++)ans += dp[i][n];
	printf("%d", ans%mod);
	return 0;
}
//#include <cstdio>
//#define mod 1000000000
//int N, dp[10][100], ans;
//int func(int n, int m) {
//	int& ref = dp[n][m];
//	if (!m)return ref = func(n - 1, 1)%mod;
//	if (m == 9)return ref = func(n - 1, 8)%mod;
//	return ref = (func(n - 1, m - 1) + func(n - 1, m + 1))%mod;
//}
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < 10; i++)dp[i][1] = 1;
//	for (int i = 0; i < 10; i++) {
//		ans+=func(N, i)%mod;
//	}
//	printf("%d", ans);
//	return 0;
//}