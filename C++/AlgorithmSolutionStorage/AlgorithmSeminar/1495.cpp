#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, m;
int v[101], cache[101][1001];

int dp(int cur, int dep) {
	if (cur<0 || cur>m)return -100;
	if (dep == n) return cur;

	int& ret = cache[dep][cur];
	if (ret != -1) return ret;

	return ret = max(dp(cur - v[dep], dep + 1), dp(cur + v[dep], dep + 1));
}

int main() {
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 0; i < n; i++)scanf("%d", &v[i]);

	fill(&cache[0][0], &cache[n][m + 1], -1);

	int result = dp(s, 0);
	printf("%d", result==-100?-1:result);
	return 0;
}