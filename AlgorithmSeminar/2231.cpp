#include <cstdio>
#include <math.h>

int main() {
	int n, m, min;

	scanf("%d", &n);

	min = n - 9 * ((int)log10(n) + 1);
	for (int i = min; i <= n - 3; i++) {
		int k = i, sum = i;
		while (k) {
			sum += k % 10;
			k /= 10;
		}
		if (sum == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}