#include <cstdio>
#include <math.h>

bool isprimenum(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0) return false;
	return true;
}

int main() {
	int n = 1;
	bool c;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	while (n) {
		c = false;
		for (int i = 3; i < n; i += 2)
			if (isprimenum(i) && isprimenum(n - i)) {
				printf("%d = %d + %d\n", n, i, n - i);
				c = true;
				break;
			}
		if (!c)
			printf("Goldbach's conjecture is wrong.\n");
		scanf("%d", &n);
	}
	return 0;
}