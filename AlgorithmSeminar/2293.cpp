#include <cstdio>
#define max(a,b) (a)>(b)?(a):(b)
int n,val[100001],dp[100001],ans=-1001;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &val[i]);
	dp[0] = val[0];
	for (int i = 0; i < n; i++)
		dp[i]=max(dp[i-1]+val[i],val[i]);
	for (int i = 0; i < n; i++)ans = max(dp[i],ans);
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//int n, k, c[101], ans,d[2][101];
//void func(int t, int p) {
//	if (!p) { ans++; return; }
//	if (p < 0)return;
//	for (int i = t; i >0; i--) func(i, p - c[i]);
//}
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < n; i++)scanf("%d", &c[i]);
//	for (int i = 0; i < k; i++) {
//
//	}
//	return 0;
//}
//#include <cstdio>
//int n, k,c[101],ans;
//void func(int t,int p) {
//	if (!p) { ans++; return; }
//	if (p < 0)return;
//	for (int i = t; i >0; i--) func(i,p-c[i]);
//}
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
//	func(n, k);
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//int n, k, val[101], ans, dp[101][10001];
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++)scanf("%d", &val[i]);
//	for (int i = 0; i <= n; i++)dp[0][i] = 1;
//	for (int i = val[1]; i <= k; i++) {
//		printf("%d : ", i);
//		for (int j = 1; j <= n; j++) {
//			dp[i][j] = dp[i][j - 1];
//			if (i - val[j] >= 0) {
//				dp[i][j] += dp[i - val[j]][j];
//			}
//			printf("%2d", dp[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d", dp[k][n]);
//	return 0;
//}
//#include <cstdio>
//int n, k, val[101], ans, dp[101][10001];
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++)scanf("%d", &val[i]);
//	for (int i = 0; i <= n; i++)dp[0][i] = 1;
//	for (int i = val[1]; i <= k; i++) {
//		//printf("%d : ", i);
//		for (int j = 1; j <= n; j++) {
//			dp[i][j] = dp[i][j - 1];
//			if (i - val[j] >= 0) {
//				 dp[i][j]+=dp[i - val[j]][j];
//			}
//			//printf("%2d", dp[i][j]);
//		}
//		//printf("\n");
//	}
//	printf("%d", dp[k][n]);
//	return 0;
//}