#include <cstdio>
int c, n, s[1001];
float m;
int main() {
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int sum = 0, p = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &s[j]);
			sum += s[j];
		}
		m = sum / n;
		for (int j = 0; j < n; j++)
			if (s[j]>m)p++;
		printf("%.3f%%\n", (float)p / n * 100);
	}
	return 0;
}