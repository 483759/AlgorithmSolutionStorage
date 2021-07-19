#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, arr[1001][1001], dp[1001][1001], ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (!i || !j || !arr[i][j])
				dp[i][j] = arr[i][j];
			else if (arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1]) {
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
			}
			else {
				dp[i][j] = 1;
			}

			if (dp[i][j] > ans)ans = dp[i][j];
		}
	printf("%d", ans * ans);
	return 0;
}