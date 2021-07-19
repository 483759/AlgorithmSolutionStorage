#include <cstdio>
#include <cstring>
using namespace std;
int dp[21][21][21],a,b,c;
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if (dp[a][b][c])
		return dp[a][b][c];

	if (a < b && b < c)
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return dp[a][b][c];
}
int main() {
	while (1) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
		memset(dp, 0, sizeof(dp));
	}
}

//#include <cstdio>
//#include <math.h>
//int L, W, H,n,cube[21];
//bool f = 1;
//int func(int l, int w, int h) {
//	if (!l || !w || !h)return 0;
//	int k = l;
//	if (w < k)k = w;
//	if (h < k)k = h;
//
//	int t = log2(k);
//	do {
//		if (!cube[t])continue;
//		cube[t]--;
//		int T = pow(2, t);
//		return func(l - T, T, h) + func(l, w - T, h) + func(T, T, h - T)+1;
//	} while (--t >= 0);
//	f = 0;
//	return -1;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d%d", &L, &W, &H,&n);
//	for (int i = 0,a,b; i < n; i++) {
//		scanf("%d%d", &a, &b);
//		cube[a] = b;
//	}
//	int ans = func(L, W, H);
//	if (f)
//		printf("%d", ans);
//	else printf("-1");
//	return 0;
//}