#include <cstdio>
#include <algorithm>
using namespace std;
int dp[13][4], tc, cost[4], day[13];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		int ans = 0;
		for (int i = 0; i < 4; i++)
			scanf("%d", &cost[i]);
		for (int i = 1; i <= 12; i++)
			scanf("%d", &day[i]);
		dp[1][0] = day[1] * cost[0];
		dp[1][1] = cost[1];
		dp[1][2] = cost[2];
		dp[1][3] = cost[3];

		for (int i = 2; i <= 12; i++) {
			int m = min(dp[i - 1][0], dp[i - 1][1]);
			if (i > 3)
				m = min(m, dp[i - 3][2]);
			dp[i][0] = m + day[i] * cost[0];
			dp[i][1] = m + (day[i] ? cost[1] : 0);
			dp[i][2] = m + (day[i]?cost[2]:0);
		}
		ans = min({ dp[12][0], dp[12][1], dp[12][2], dp[1][3] });
		printf("#%d %d\n", T, ans);
	}
	return 0;
}