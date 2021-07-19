#include <cstdio>
#include <algorithm>
using namespace std;
#define safe(x,y) x>=0&&x<m&&y>=0&&y<n
int n, m, dp[1001][1001], arr[1001][1001], t;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			t = 0;
			if (safe(j - 1, i - 1))t = max(dp[i - 1][j - 1], t);
			if (safe(j, i - 1))t = max(dp[i - 1][j], t);
			if (safe(j - 1, i))t = max(dp[i][j - 1], t);
			dp[i][j] = t + arr[i][j];
		}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		printf("%3d", dp[i][j]);
	//	printf("\n");
	//}
	printf("%d", dp[n - 1][m - 1]);
	return 0;
}