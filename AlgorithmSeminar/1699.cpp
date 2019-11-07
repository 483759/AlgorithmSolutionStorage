#include <cstdio>
#include <math.h>
int n, dp[100001] = { 0,1 };
int main() {
	scanf("%d", &n);
	for (int i = 2,min; i <= n; i++) {
		min = 987654321;
		for (int j = 1; j <= sqrt(i); j++)
			min = dp[i - j * j] < min ? dp[i - j * j] : min;
		dp[i] = min + 1;
	}
	printf("%d", dp[n]);
	return 0;
}