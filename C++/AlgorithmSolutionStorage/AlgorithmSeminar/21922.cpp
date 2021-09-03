#include <cstdio>

int board[2005][2005];
int item[5][4] = {
	{0,0,0,0},
	{0,3,2,1},
	{2,1,0,3},
	{1,0,3,2},
	{3,2,1,0}
};
int n, m, dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };
bool visit[2005][2005][4];

bool safe(int x, int y) {
	return x >= 0 && x < m&& y >= 0 && y < n;
}

void dfs(int x, int y, int d) {
	if (!safe(x, y) || visit[y][x][d])return;
	visit[y][x][d] = true;

	int nd = d;
	if (board[y][x] >= 1 && board[y][x] <= 4)
		nd = item[board[y][x]][d];

	int nx = x + dx[nd], ny = y + dy[nd];
	dfs(nx, ny, nd);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &board[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 9)continue;

			for (int k = 0; k < 4; k++)
				dfs(j, i, k);
		}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			bool b = false;
			for (int k = 0; k < 4; k++)
				b |= visit[i][j][k];
			if (b)ans++;
		}
	printf("%d", ans);
	return 0;
}