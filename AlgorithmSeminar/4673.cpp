#include <cstdio>
bool self[10001];
int main() {
	for (int i = 1; i <= 10000; i++) {
		int j = i;
		if (self[j])continue;
		while (j < 10001) {
			for (int k = j; k != 0; k /= 10)
				j += k % 10;
			self[j] = true;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (self[i])continue;
		printf("%d\n", i);
	}
	return 0;
}