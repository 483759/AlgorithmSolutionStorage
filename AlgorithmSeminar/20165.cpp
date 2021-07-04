#include <iostream>
using namespace std;

int map[105][105],origin[105][105];
int n, m, r,ans;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char dir[] = { 'E','S','W','N' };

bool safe(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int dfs(int x, int y, int d) {
	int size = map[y][x],score=1;
	map[y][x] = -1;

	int nx = x, ny = y;
	for (int i = 0; i < size; i++) {
		if (safe(nx, ny) && map[ny][nx] != -1) {
			score+=dfs(nx, ny, d);
		}

		nx += dx[d], ny += dy[d];
	}

	return score;
}

int main() {
	cin >> n >> m >> r;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; origin[i][j] = map[i][j];
		}

	while (r--) {
		int x, y; char d;
		cin >> y >> x >> d;
		for(int i=0;i<4;i++)
			if (dir[i] == d) {
				ans+=dfs(x-1, y-1, i);
				break;
			}
		cin >> y >> x;
		x--; y--;
		map[y][x] = origin[y][x];
	}

	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1)printf("F ");
			else printf("S ");
		}
		printf("\n");
	}
	return 0;
}