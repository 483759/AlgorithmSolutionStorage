#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int t, s, arr[1001], dp[1001], N, k, w;
int cnt[100001][2];
int func(int n) {
	int& ref = dp[n];
	if (ref!=-1)return ref;
	int max = 0, c=0;
	for (int i = 0, temp; i < k; i++) {
		if (cnt[i][1] == n) {
			temp = func(cnt[i][0]);
			max = temp > max ? temp : max;
			c++;
		}
	}
	if (!c)return arr[n];
	return ref = max + arr[n];
}
int main() {
	scanf("%d", &t);
	for (int e = 0; e < t; e++) {
		memset(cnt, false, sizeof(cnt));
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &N, &k);
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		for (int i = 0, a, b; i < k; i++) {
			scanf("%d%d", &a, &b);
			cnt[i][0] = a; cnt[i][1] = b;
			if (!i)s = a;
		}
		scanf("%d", &w);
		printf("%d\n", func(w));
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int t, n, k, w, ans, dep;
//struct s { int num, b, d; };
//s arr[1001];
//bool cmp(s a, s b) {
//	if (a.d == b.d)return a.b > b.b;
//	return a.d < b.d;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &t);
//	for (int q = 0; q < t; q++) {
//		ans = 0;
//		scanf("%d%d", &n, &k);
//		for (int i = 1; i <= n; i++) {
//			scanf("%d", &arr[i].b);
//			arr[i].num = i;
//		}
//		for (int i = 0, a, b; i < k; i++) {
//			scanf("%d%d", &a, &b);
//			if (!i)arr[a].d = 1;
//			arr[b].d = arr[a].d + 1;
//		}
//		scanf("%d", &w);
//		sort(arr, arr + n, cmp);
//		dep = arr[w].d;
//		for (int i = 0; i < w; i++) {
//			if (arr[i].d != arr[i + 1].d)ans += arr[i + 1].b;
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}