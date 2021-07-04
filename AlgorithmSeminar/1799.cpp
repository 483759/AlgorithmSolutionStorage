#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct { int x, y; }point;
int n, ans[2],dx[] = { 1,1,-1,-1 }, dy[] = { 1,-1,1,-1 };
bool can[11][11], map[11][11];
bool num[101];
vector<point> v[2];
bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
void move(point cur, bool pre[][11]) {
	pre[cur.y][cur.x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i], ny = cur.y + dy[i];
		while (safe(nx, ny)) {
			pre[ny][nx] = 1;
			nx += dx[i]; ny += dy[i];
		}
	}
}
void back(int dep, int sum,int color) {
	if (dep == v[color].size()) {
		if (sum > ans[color])
			ans[color] = sum;
		return;
	}
	bool pre[11][11];
	back(dep + 1, sum,color);
	point cur = v[color][dep];
	memcpy(pre, map, sizeof(map));
	if (!map[cur.y][cur.x]) {
		move(cur, map); num[dep] = 1;
		back(dep + 1, sum + 1,color);
		memcpy(map, pre, sizeof(pre)); num[dep] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int k;	scanf("%d", &k);
			if (k)v[(i+j)%2].push_back({ j,i });
		}
	back(0, 0, 0); back(0, 0, 1);
	printf("%d", ans[0]+ans[1]);
	return 0;
}