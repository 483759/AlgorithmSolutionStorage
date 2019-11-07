#include <cstdio>
int n, ans, a[1000001], d[1000001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (d[i] - 1 > j)break;
			if (a[j]<a[i] && d[j] + 1>d[i])
				d[i] = d[j] + 1;
		}
	}
	for (int i = 0; i < n; i++)ans = d[i] > ans ? d[i] : ans;
	printf("%d", ans);
	return 0;
}
