#include <cstdio>
#define ull unsigned long long

ull wire[10005];
int n, k;
ull left, right, ans;

int main() {
	scanf("%d%d", &k,&n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &wire[i]);
	}

	right = (1LL << 31) - 1;
	while (left <= right) {
		ull mid = (left + right) / 2;

		ull cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += wire[i] / mid;

		if (cnt >= n) {
			ans = mid > ans ? mid : ans;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}