#include <cstdio>
int n, g[11], d;
int main() {
	scanf("%d", &n);
	for (int i = 1, j; i <= n; i++) {
		scanf("%d", &d);
		for (j = 1; j <= n; j++)
			if (!g[j]) {
				if (!d)g[j] = i;
				d--;
			}
	}
	for (int i = 1; i <= n; i++)printf("%d ", g[i]);
	return 0;
}
//
//1��-3��°
//2��-2��°
//3��-1or4��°
//4��-