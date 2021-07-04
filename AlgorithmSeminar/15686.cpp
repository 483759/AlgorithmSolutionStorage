#include <cstdio>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;
int n, m, map[51][51], ans= 500000, h, check[13];
bool b[51][51], visit[51][51];
struct point { int r, c; };
vector<point> v, house;
void func(int num, int dep) {
	if (dep == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dis = 500000;
			for (int j = 0, k; j < m; j++) {
				k = abs(house[i].r - v[check[j]].r) + abs(house[i].c - v[check[j]].c);
				if (k < dis)dis = k;
			}
			sum += dis;
		}
		if (sum < ans)ans = sum;


		memset(b, false, sizeof(b));
		return;
	}

	for (int i = num + 1; i < v.size(); i++) {
		check[dep] = i;
		func(i, dep + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				house.push_back({ i,j });
			if (map[i][j] == 2)
				v.push_back({ i,j });

		}
	func(-1, 0);
	printf("%d", ans);
	return 0;
}