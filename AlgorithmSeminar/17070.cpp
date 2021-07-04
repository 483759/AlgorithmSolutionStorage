#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, k, cnt, ans, arr[100005];
queue<int> q;
vector<int> v;
int main() {
	scanf("%d%d", &n, &k);
	fill(&arr[0], &arr[100001], -1);
	arr[n] = n;
	q.push(n);

	if (n == k) { printf("0\n%d", n); return 0; }

	while (!q.empty()) {
		for (int i = q.size(); i > 0; i--) {
			int x = q.front(); q.pop();

			if (x + 1 <= 100000 && arr[x + 1] == -1) {
				arr[x + 1] = x;
				q.push(x + 1);
			}
			if (x - 1 >= 0 && arr[x - 1] == -1) {
				arr[x - 1] = x;
				q.push(x - 1);
			}
			if (x * 2 <= 100000 && arr[x * 2] == -1) {
				arr[x * 2] = x;
				q.push(x * 2);
			}
		}
		ans++;
		if (arr[k] != -1)break;
	}

	int t = k;
	while (t != n) {
		v.push_back(t);
		t = arr[t];
	}
	v.push_back(n);

	printf("%d\n", ans);
	for (int i = v.size() - 1; i > 0; i--)
		printf("%d ", v[i]);
	printf("%d", v[0]);
	return 0;
}


//#include <cstdio>
//
//int n, map[17][17], dp[3][17][17];
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &map[i][j]);
//		}
//	for (int i = 0; i <= n; i++)
//		map[i][n] = map[n][i] = 1;
//
//	dp[0][0][1] = 1;
//	for(int i=0;i<n;i++)
//		for (int j = 1; j < n; j++) {
//			if (!map[i][j + 1]) {
//				dp[0][i][j + 1] += dp[0][i][j];
//				dp[0][i][j + 1] += dp[1][i][j];
//			}
//
//			if (!map[i][j + 1]&&!map[i + 1][j + 1]&& !map[i + 1][j]) {
//				dp[1][i + 1][j + 1] += dp[0][i][j];
//				dp[1][i + 1][j + 1] += dp[1][i][j];
//				dp[1][i + 1][j + 1] += dp[2][i][j];
//			}
//
//			if (!map[i + 1][j]) {
//				dp[2][i + 1][j] += dp[1][i][j];
//				dp[2][i + 1][j] += dp[2][i][j];
//			}
//
//		}
//	printf("%d", dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1]);
//	return 0;
//}

//#include <cstdio>
//struct point { int x, y; };
//int n, ans;
//bool map[17][17], dx[] = { 1, 1, 0 }, dy[] = { 0, 1, 1 };
//bool safe(int x, int y) {
//	return x >= 0 && x < n && y >= 0 && y < n && !map[y][x];
//}
//bool canMove(int x, int y, int d) {
//	switch (d) {
//	case 0:
//		return safe(x + 1, y);
//	case 1:
//		return safe(x + 1, y) && safe(x, y + 1) && safe(x + 1, y + 1);
//	case 2:
//		return safe(x, y + 1);
//	default:
//		break;
//	}
//}
//void func(int cx, int cy, int d) {
//	int nx = cx + dx[d], ny = cy + dy[d], s, f;
//	if ((nx == n - 1) && (ny == n - 1))ans++;
//	switch (d) {
//	case 0:
//		s = 0; f = 1;
//		break;
//	case 1:
//		s = 0; f = 2;
//		break;
//	case 2:
//		s = 1; f = 2;
//		break;
//	default:
//		break;
//	}
//	for (int i = s; i <= f; i++)
//		if (canMove(nx, ny, i))
//			func(nx, ny, i);
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%d", &map[i][j]);
//	func(0, 0, 0);
//	printf("%d", ans);
//	return 0;
//}