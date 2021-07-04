#include <cstdio>
int n, num[10],m;
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &n); num[n]++;
	}
	for (int i = 1; i <= 6; i++) {
		if (num[i] <= 1) {
			if (num[i] == 1)m = i;
			continue;
		}
		else if (num[i] == 3)printf("%d", 10000 + i * 1000);
		else if (num[i] == 2)printf("%d", 1000 + i * 100);
		return 0;
	}
	printf("%d", m * 100);
	return 0;
}