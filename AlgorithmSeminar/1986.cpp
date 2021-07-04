#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct { int x, y; }point;
vector<point> v[3];
int n, m, t, ans, map[1005][1005], dx[][8] = { {0,1,1,1,0,-1,-1,-1},{1,2,2,1,-1,-2,-2,-1} }, dy[][8] = { {-1,-1,0,1,1,1,0,-1},{-2,-1,1,2,2,1,-1,-2} };
bool visit[1005][1005];

bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

void input(int b) {
	scanf("%d", &t);
	while (t--) {
		int r, c; scanf("%d%d", &r, &c);
		map[r - 1][c - 1] = b;
		visit[r - 1][c - 1] = 0;
		ans--;
		v[b - 1].push_back({ c-1,r-1 });
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(visit, 1, sizeof(visit));
	ans = n * m;
	input(1); input(2); input(3);
	
	for (point p : v[0]) {
		for (int i = 0; i < 8; i++) {
			int nx = p.x+dx[0][i],ny=p.y+dy[0][i];
			while (safe(nx, ny) && !map[ny][nx]) {
				if (visit[ny][nx])ans--;
				visit[ny][nx] = 0;
				nx += dx[0][i]; ny += dy[0][i];
			}
		}
	}

	for (point p : v[1]) {
		for (int i = 0; i < 8; i++) {
			int nx = p.x + dx[1][i], ny = p.y + dy[1][i];
			if (safe(nx, ny) && !map[ny][nx]) {
				if (visit[ny][nx])ans--;
				visit[ny][nx] = 0;
			}
		}
	}

	printf("%d", ans);
	return 0;
}