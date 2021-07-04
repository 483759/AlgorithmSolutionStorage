#include <cstdio>
#include <vector>
using namespace std;
typedef struct {
	int x, y;
}point;
int tc, n, k, map[10][10], ans, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
vector<point> v;
bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs(point p, int dep) {
	bool b = 0;
	for (int i = 0; i < 4; i++) {
		int nx = p.x + dx[i], ny = p.y + dy[i];
		if (safe(nx, ny) && map[ny][nx] < map[p.y][p.x]) {
			dfs({ nx,ny }, dep + 1);
			b = 1;
		}
	}
	if (!b && dep > ans)ans = dep;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		ans = 1;
		int max = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > max)max = map[i][j];
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j] == max)v.push_back({ j,i });

		for (auto x : v) {
			dfs(x, 0);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int temp = map[i][j];
				for (int d = 1; d <= k; d++) {
					map[i][j]--;
					for (auto x : v) {
						if (x.x == j && x.y == i)continue;
						dfs(x, 1);
					}
				}
				map[i][j] = temp;
			}

		printf("#%d %d\n", T, ans);
		v.clear();
	}
	return 0;
}
