#include <cstdio>
int n, dp[31] = {1,0};
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	printf("%d", dp[n]);
	return 0;
}