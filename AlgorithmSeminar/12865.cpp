#include <cstdio>
#include <algorithm>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
int n, k, w[101], v[101], dp[101][100001];
int knap(int i, int cap) {
	if (i == n)return 0;
	int& ret = dp[i][cap];
	if (ret != -1)return ret;

	if (cap - w[i] >= 0)
		ret = knap(i + 1, cap - w[i]) + v[i];
	ret = max(knap(i + 1, cap), ret);
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)scanf("%d%d", &w[i], &v[i]);
	fill(&dp[0][0], &dp[100][100001], -1);
	printf("%d", knap(0, k));
	return 0;
}
//6  4 3 5
//13 8 6 12