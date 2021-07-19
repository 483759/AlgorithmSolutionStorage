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
//1번-3번째
//2번-2번째
//3번-1or4번째
//4번-