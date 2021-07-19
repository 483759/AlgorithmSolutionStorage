#include <cstdio>
#include <algorithm>
int a, b, c, n, *max;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	max = a > b ? (a > c ? &a : &c) : (b > c ? &b : &c);
	*max -= *max;
	n = a > b ? (a > c ? a : c) : (b > c ? b : c);
	printf("%d", n);
	return 0;
}