#include <cstdio>
long long ans;
int n, k;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		ans += k - 1;
	}
	printf("%lld", ans+1);
	return 0;
}