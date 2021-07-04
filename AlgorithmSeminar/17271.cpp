#include <cstdio>
#define MOD 1000000007

int dp[10105] = { 1 };
int n,m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
		dp[i + m] = (dp[i + m] + dp[i]) % MOD;
	}
	printf("%d", dp[n]%MOD);
	return 0;
}