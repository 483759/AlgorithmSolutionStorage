#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int check[1001][3];
int dp[1001][3];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &check[i][0], &check[i][1], &check[i][2]);
	dp[0][0] = check[0][0]; dp[0][1] = check[0][1]; dp[0][2] = check[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + check[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + check[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + check[i][2];
	}
	printf("%d", min(min(dp[n - 1][0], dp[n - 1][1]),dp[n-1][2]));
	return 0;
}

//#include <cstdio>
//int n, min = 1000000;
//int check[3][1001];
//void func(int t, int k, int cost) {
//	if (cost > min)return;
//	if (t == n) {
//		if (cost < min)min = cost;
//		return;
//	}
//	for (int i = 0; i < 3; i++) {
//		if (i == k)continue;
//		func(t + 1, i, cost + check[i][t]);
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d%d%d", &check[0][i], &check[1][i], &check[2][i]);
//	func(0, -1, 0);
//	printf("%d", min);
//	return 0;
//}