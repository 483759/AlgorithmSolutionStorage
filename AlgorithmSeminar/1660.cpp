#include <cstdio>
#include <algorithm>
using namespace std;

int n, dp[300005], tet[150];

int func(int x) {
	if (x == 0)return 0;

	int& ret = dp[x];
	if (ret != -1)return ret;

	ret = 300001;
	for (int i = 1; i <= 150; i++) {
		if (tet[i] > x)break;
		ret = min(ret, 1 + func(x - tet[i]));
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 150; i++)tet[i] = tet[i - 1] + (i * (i + 1)) / 2;

	fill(&dp[0], &dp[n + 1], -1);
	printf("%d", func(n));
	return 0;
}