#include <cstdio>
#define max(a,b) a>b?a:b
int n, ans=-1001, val[100001], dp[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
		dp[i] = max(dp[i - 1] + val[i], val[i]);
		ans = max(dp[i], ans);
	}
	printf("%d", ans);
	return 0;
}