#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, arr[505][505], dp[505][505], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool safe(int x, int y) { return x > 0 && x <= m && y > 0 && y <= n; }
int dfs(int x,int y) {
	if (x == m && y == n)
		return 1;
	if (dp[y][x] == INF) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!safe(nx, ny))continue;
			if (arr[ny][nx] < arr[y][x])
				dp[y][x] += dfs(nx, ny);
		}
	}
	return dp[y][x];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	fill(&dp[1][1], &dp[n + 2][m+1], 987654321);
	printf("%d",dfs(1, 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%3d", dp[i][j]==INF?-1:dp[i][j]);
		printf("\n");
	}
			return 0;
}