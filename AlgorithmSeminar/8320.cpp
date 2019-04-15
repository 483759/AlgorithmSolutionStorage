#include <cstdio>
#include <math.h>
int n, cnt;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= sqrt(n); i++)
		for (int j = i; j <= (double)(n / i); j++)
			if (i*j <= n)cnt++;
	printf("%d", cnt);
	return 0;
}