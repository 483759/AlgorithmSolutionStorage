#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
typedef struct { int k, x, y; }point;
int n, ans, arr[501][501], dp[501][501], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
vector<point> v;
bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
bool cmp(point a, point b) { return a.k < b.k; }
int func(int x, int y) {
	if (dp[y][x] != INF)return dp[y][x];
	dp[y][x] = 1;
	int max = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!safe(nx, ny) || arr[ny][nx] <= arr[y][x])continue;
		int t = func(nx, ny) + 1;
		if (t > max)max = t;
	}
	return dp[y][x] = max;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			v.push_back({ arr[i][j],j,i });
			dp[i][j] = INF;
		}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
		if (dp[x.y][x.x] == INF) {
			int k = func(x.x, x.y);
			if (k > ans)ans = k;
		}
	printf("%d", ans);
	return 0;
}