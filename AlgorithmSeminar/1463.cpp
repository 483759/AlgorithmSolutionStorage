#include <cstdio>
char m[101][101];
int n;
int bfs(int r, int c) {

}
int main() {
	for (int i = 0; i < n; i++)
		scanf("%s", m[i]);
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {

		}
	return 0;
}
//#include <cstdio>
//int dp[1000001], x;
//int main() {
//	scanf("%d", &x);
//	for (int i = 2, b; i <= x; i++) {
//		int a = b = 1000000;
//		if (i % 3 == 0)a = dp[i / 3];
//		if (i % 2 == 0)a = dp[i / 2]<a?dp[i/2]:a;
//		dp[i] = dp[i - 1] < a ? dp[i - 1] + 1 : a + 1;
//	}
//	printf("%d", dp[x]);
//	return 0;
//}
//#include <cstdio>
//int dp[100001], x;
//int func(int n) {
//	if (n == 1)return 0;
//	if (dp[n])return dp[n];
//	dp[n] = func(n - 1) + 1;
//	if (!(n % 2)) {
//		int t = func(n / 2) + 1;
//		dp[n] = dp[n] < t ? dp[n] : t;
//	}
//	if (!(n % 3)) {
//		int t = func(n / 3) + 1;
//		dp[n] = dp[n] < t ? dp[n] : t;
//	}
//	return dp[n];
//}
//int main() {
//	scanf("%d", &x);
//	printf("%d", func(x));
//	return 0;
//}

//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int arr[1000001], N;
//int func(int X) {
//	if (X == 1)return 0;
//	int& ref = arr[X];
//	if (ref)return ref + 1;
//	ref = func(X - 1);
//	if (X % 3 == 0)ref = min(func(X / 3), ref);
//	if (X % 2 == 0)ref = min(func(X / 2), ref);
//	return ref + 1;
//}
//int main() {
//	scanf("%d", &N);
//	printf("%d", func(N));
//	return 0;
//}