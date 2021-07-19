#include <cstdio>
#include <algorithm>
using namespace std;
int n, arr[100001][3], dp[100001][3];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)scanf("%d", &arr[i][j]);
		if (!i) {
			for (int j = 0; j < 3; j++)dp[i][j] = arr[i][j];
			continue;
		}
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
		dp[i][1] = max({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }) + arr[i][1];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][2];
	}
	printf("%d ", max({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] }));

	for (int i = 0; i < n; i++) {
		if (!i) continue;
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
		dp[i][1] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][2];
	}
	printf("%d", min({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] }));
	return 0;
}