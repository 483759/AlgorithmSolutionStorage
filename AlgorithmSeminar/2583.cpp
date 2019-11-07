#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define safe(x,y) x>=0&&x<n&&y>=0&&y<m
struct point { int x, y; };
vector<int> v;
int cnt, m, n, k, lx, ly, rx, ry, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool map[101][101], visit[101][101];
void dfs(point cur) {
	visit[cur.y][cur.x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx=cur.x+dx[i], ny=cur.y+dy[i];
		if (safe(nx,ny)&&!visit[ny][nx] && !map[ny][nx])
			dfs({nx,ny});
	}
}
int main() {
	scanf("%d%d%d", &m, &n, &k);
	for (int t = 0; t < k; t++)	{
		scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
		for (int i = lx; i < rx; i++)
			for (int j = ly; j < ry; j++)
				map[j][i] = true;
	}

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if (!map[i][j] && !visit[i][j]) {
				dfs({ j, i });
				v.push_back(cnt);
				cnt = 0;
			}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	return 0;
}