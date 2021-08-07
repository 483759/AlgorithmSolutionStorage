#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, l[100005], dp[2][100005],ans;

int func(bool b, int cur) {
	if (cur == n)return 1;

	int& ret = dp[b][cur];
	if (ret != -1)return ret;

	int dep = 1;
	ret = 1;

	if (l[cur] <= k)
		ret = func(b, cur + 1) + 1;
	else if (!b)
		ret = max(func(true, cur + 1) + 1, dep);

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &l[i]);

	fill(&dp[0][0], &dp[1][100001], -1);
	dp[0][n] = dp[1][n] = 1;

	for (int i = 1; i <= n; i++)
		ans = max(ans, func(false, i));

	printf("%d", ans);
	return 0;
}