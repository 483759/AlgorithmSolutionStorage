#include <cstdio>
int n[5], s;
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n[i]);
		if (n[i] < 40)n[i] = 40;
		s += n[i];
	}
	printf("%d", s / 5);
	return 0;
}