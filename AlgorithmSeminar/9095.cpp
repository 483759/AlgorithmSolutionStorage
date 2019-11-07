#include <cstdio>
int dp[12] = { 0, 1, 2, 4 }, t;
int plus(int n) {
	if (n <= 3 || dp[n])return dp[n];
	else {
		dp[n] = plus(n - 1) + plus(n - 2) + plus(n - 3);
		return dp[n];
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0, n; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", plus(n));
	}
	return 0;
}
//1
//1
//
//2
//1 1
//
//3
//1 1 1
//1 2
//2 1