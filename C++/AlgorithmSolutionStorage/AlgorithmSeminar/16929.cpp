#include <cstdio>
#include <vector>
#define ull unsigned long long
using namespace std;

vector<int> tree;
int n, m, left, right, ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,th; i < n; i++) {
		scanf("%d", &th);
		tree.push_back(th);
		if (th > right)right = th;
	}

	while (left <= right) {
		int h = (left + right) / 2;

		ull sum = 0;
		for (int i = 0; i < n; i++)
			if (tree[i] > h)sum += (ull)tree[i] - h;

		if (sum >= m) {
			left = h + 1;
			if (h > ans)ans = h;
		}
		else right = h - 1;

	}
	printf("%d", ans);
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string map[51];
//int n, m;
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool visit[51][51];
//
//bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
//
//bool dfs(int x, int y, int dep, int pre) {
//	visit[y][x] = 1;
//	for (int i = 0; i < 4; i++) {
//		if (i == pre)continue;
//		int nx = x + dx[i], ny = y + dy[i];
//		if (!safe(nx, ny) || map[ny][nx] != map[y][x])continue;
//		if (visit[ny][nx])return true;
//		if (dfs(nx, ny, dep + 1, (i+2)%4))return true;
//	}
//	return false;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//		cin >> map[i];
//
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < m; j++) {
//			if (!visit[i][j])
//				if (dfs(j, i, 0, -1)) {
//					cout << "Yes";
//					return 0;
//				}
//		}
//	cout << "No";
//	return 0;
//}