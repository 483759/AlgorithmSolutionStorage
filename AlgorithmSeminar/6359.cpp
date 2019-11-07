#include <cstdio>
int n, dp[100001] = {1,3};
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1]*2+dp[i-2])%9901;
	printf("%d", dp[n]);
	return 0;
}
//#include <cstdio>
//int n, t,dp[101];
//int main() {
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++)
//			if (i*i > n) { printf("%d\n", i - 1); break; }
//	}
//	return 0;
//}