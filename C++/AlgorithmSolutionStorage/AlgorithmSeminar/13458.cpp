#include <cstdio>
int n, b, c;
long long a[1000001], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lld", &a[i]);
	scanf("%d%d", &b, &c);
	for (int i = 0; i < n; i++) {
		a[i] -= b; ans++;
		if (a[i] <= 0)continue;
		ans += (a[i] % c == 0) ? (a[i] / c) : (a[i] / c + 1);
	}
	printf("%lld", ans);
	return 0;
}