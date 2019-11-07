#include <cstdio>
int n, m, dp[11][11];
char map[11][11];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%c", &map[i][j]);

	return 0;
}