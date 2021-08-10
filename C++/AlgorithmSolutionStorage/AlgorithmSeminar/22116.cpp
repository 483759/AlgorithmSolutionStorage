#include <cstdio>
#include <vector>
#include <math.h>
#include <cstring>
#define ll long long
using namespace std;

int map[1001][1001], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, n;
bool visit[1001][1001];

bool safe(int x, int y) { return x >= 0 && x < n&& y >= 0 && y < n; }

bool dfs(int x, int y, int l) {
	if (x == n - 1 && y == n - 1)return true;

	visit[y][x] = true;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (safe(nx, ny) && !visit[ny][nx] && (abs(map[ny][nx] - map[y][x]) <= l)) {
			flag |= dfs(nx, ny, l);
		}
	}
	return flag;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}

	ll left = -1, right = 1000000000;
	while (left + 1 < right) {
		ll mid = (left + right) / 2;
		if (dfs(0, 0, mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
		memset(visit, false, sizeof visit);
	}
	printf("%lld", right);
	return 0;
}