#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;
int main() {
	int n, x, y, d, g, ans=0, dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 };
	bool v[101][101];
	vector<int> vec;
	memset(v, false, sizeof(v));
	scanf("%d", &n);
	for (int a = 0; a < n; a++) {
		scanf("%d%d%d%d", &x, &y, &d, &g);
		vec.push_back(d); v[y][x] = 1;
		for (int i = 1, temp; i <= g; i++)
			for (int j = vec.size() - 1; j >= 0; j--)
				vec.push_back((vec[j] + 1) % 4);
		for (int i = 0, cx = x, cy = y; i < vec.size(); i++) {
			cx += dx[vec[i]]; cy += dy[vec[i]];
			v[cy][cx] = 1;
		}
		while (!vec.empty())vec.pop_back();
	}
	for (int i = 0; i<100; i++)
		for (int j = 0; j < 100; j++)
			if (v[i][j] && v[i + 1][j] && v[i][j + 1] && v[i + 1][j + 1])ans++;
	printf("%d", ans);
	return 0;
}