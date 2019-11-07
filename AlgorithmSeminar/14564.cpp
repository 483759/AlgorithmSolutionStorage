#include <cstdio>
int n, m, a, t;
int main() {
	scanf("%d%d%d", &n, &m, &a);
	while (1) {
		scanf("%d", &t);
		if (t == (m / 2) + 1) { printf("0"); return 0; }
		a += t - m / 2 - 1;
		if (a > n)a = a % n;
		if (a < 1)a += n;
		printf("%d\n",a);
	}
	return 0;
}