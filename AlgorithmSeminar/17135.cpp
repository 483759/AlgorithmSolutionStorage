#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct point { int d, x, y; };
int n, m, d, ans, map[30][30];
bool e[16][16];
vector<point> v[3], del; 
vector<point>::iterator it;
bool cmp(point a, point b) {
	if (a.d == b.d)return a.x < b.x;
	return a.d < b.d;
}
int func(int* arr) {
	int max = 0;
	memset(e, false, sizeof(e));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 3; k++) {
				if (map[i][j]) {
					v[k].push_back({ abs(j - arr[k]) + abs(n - i) ,j,i });
				}
			}
	for (int k = 0; k < 3; k++)
		sort(v[k].begin(), v[k].end(), cmp);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0, k; j < 3; j++) {
			for (it = v[j].begin(); it != v[j].end(); it++)
				if (!e[(*it).y][(*it).x] && (*it).y <= i && (*it).d <= d + n - i - 1)
					break;

			if (it != v[j].end())
				del.push_back({ 0,(*it).x,(*it).y });
		}

		for (int j = 0; j < del.size(); j++) {
			if (e[del[j].y][del[j].x])continue;
			max++;
			e[del[j].y][del[j].x] = true;
		}
		del.clear();
	}
	for (int k = 0; k < 3; k++)
		v[k].clear();

	return max;

}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < m - 2; i++)
		for (int j = i + 1; j < m - 1; j++)
			for (int k = j + 1; k < m; k++) {
				int ac[3], t;
				ac[0] = i, ac[1] = j, ac[2] = k;
				t = func(ac);
				ans = t > ans ? t : ans;
			}
	printf("%d", ans);
	return 0;
}