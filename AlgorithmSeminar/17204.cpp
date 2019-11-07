#include <cstdio>
int n, k, cur, ans, arr[151];
bool v[151];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	for (; cur != k; cur = arr[cur], ans++) {
		if (v[cur])return printf("-1");
		v[cur] = 1;
	}
	printf("%d", ans);
	return 0;
}