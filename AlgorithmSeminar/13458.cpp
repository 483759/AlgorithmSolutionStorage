#include <cstdio>
int n, x, a[10001], min[10001], j;
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < x)min[j++] = a[i];
	}
	for (int i = 0; i < j; i++)printf("%d ", min[i]);
	return 0;
}

//#include <cstdio>
//int n, b, c, a[1000001], ans;
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
//	scanf("%d%d", &b, &c);
//	for (int i = 0; i < n; i++) {
//		a[i] -= b; ans++;
//		if (a[i] <= 0)continue;
//		ans += (a[i] % c == 0) ? (a[i] / c) : (a[i] / c + 1);
//	}
//	printf("%d", ans);
//	return 0;
//}