#include <cstdio>
int t, n;
bool ans[21];
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int k = 0;
		scanf("%d", &n);
		for (int j = 0; j < 21; j++)ans[j] = 0;
		while (n) {
			if (n & 1)ans[k] = 1;
			k++;
			n >>= 1;
		}
		for (int j = 0; j < 21; j++)
			if (ans[j])printf("%d ", j);
		printf("\n");
	}
	return 0;
}