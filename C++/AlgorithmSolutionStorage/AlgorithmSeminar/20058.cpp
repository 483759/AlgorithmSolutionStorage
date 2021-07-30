#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define pow2(x) (1<<(x))
using namespace std;

int n, q, s, len;
int a[129][129], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int temp[129][129];
bool visit[129][129];

bool safe(int x, int y) { return x >= 0 && x < len && y >= 0 && y < len; }

void melting() {
	vector<pii> v;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++) {
			if (!a[i][j])continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k], ny = i + dy[k];
				if (safe(nx, ny) && a[ny][nx] > 0)cnt++;
			}
			if (cnt < 3)v.push_back(make_pair(i, j));
		}
	while (!v.empty()) {
		a[v.back().first][v.back().second]--;
		v.pop_back();
	}
}

void divideAndRotate(int s) {
	int l = pow2(s);
	for (int i = 0; i < len; i += l)
		for (int j = 0; j < len; j += l) {
			for (int y = 0; y < l; y++)
				for (int x = 0; x < l; x++) {
					temp[y][x] = a[i + l - 1 - x][j + y];
				}

			for (int y = 0; y < l; y++)
				for (int x = 0; x < l; x++) {
					a[i + y][j + x] = temp[y][x];
				}
		}
}

int dfs(int x, int y) {
	if (visit[y][x])return 0;
	visit[y][x] = true;

	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!safe(nx, ny) || visit[ny][nx] || a[ny][nx] == 0)continue;
		cnt += dfs(nx, ny);
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &q); len = pow2(n);
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)scanf("%d", &a[i][j]);
	while (q--) {
		scanf("%d", &s);
		divideAndRotate(s);
		melting();
	}
	int sum = 0, m = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++) {
			sum += a[i][j];
			if (a[i][j] && !visit[i][j]) {
				int cnt = dfs(j, i);
				m = max(cnt, m);
			}
		}
	printf("%d\n%d", sum, m);
	return 0;
}