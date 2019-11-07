#include <cstdio>
#define max(a,b) a>b?a:b
int n, m, t;
long long f, ans;
int main() {
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		scanf("%d%d", &n, &m);
		f = ans = 1;
		if (n > m / 2)n = m - n;
		for (int i = 1; i <= n; i++)f *= i;
		for (int i = m; i > m - n; i--)ans *= i;
		printf("%lld\n", ans / f);
	}
	return 0;
}