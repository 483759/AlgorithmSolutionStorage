#include <cstdio>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
int n, val[301], dp[301];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &val[i]);
	dp[1] = val[1]; dp[2] = dp[1] + val[2];
	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i - 3] + val[i - 1] + val[i], dp[i - 2] + val[i]);
	printf("%d", dp[n]);
	return 0;
}
//#include <cstdio>
//#define max(a,b) a>b?a:b
//int n, arr[301], dp[301];
//int func(int num, int cnt) {
//	if (!cnt||num<=0)return 0;
//	if (dp[num])return dp[num];
//	return dp[num] = arr[num]
//		+ max(func(num - 1, cnt - 1),
//			func(num - 2, 2));
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
//	printf("%d", func(n, 2));
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n;
//int arr[10001];
//int val[10001];
//int func(int N, int cnt) {
//	if (!N)return 0;
//	if (N == 1)return val[1];
//	int& ref = arr[N];
//	if (ref != -1)return arr[N];
//	if (cnt == 2) return ref = val[N] + func(N - 2, 0);
//	return ref = val[N] + max(func(N - 1, cnt + 1), func(N - 2, 0));
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &val[i]);
//	fill(arr, arr + 10001, -1);
//	printf("%d", func(n, 0));
//	return 0;
//}