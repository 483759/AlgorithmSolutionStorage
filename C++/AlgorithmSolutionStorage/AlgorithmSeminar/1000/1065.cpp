#include <cstdio>

int main() {
	int n, cnt = 0;

	scanf("%d", &n);

	for (int i = 1, sub = 0; i <= n; i++) {
		int k = i, m = 0;
		bool c = true;

		sub = k % 10 - (k / 10) % 10;
		while (k/10) {
			m = k % 10 - (k / 10) % 10;
			k /= 10;
			if (m != sub)
				cnt++;
		}

	}
	printf("%d", n - cnt);
	return 0;
}