#include <cstdio>
int tc;
float p, q,s1,s2;
int main() {
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		scanf("%f%f", &p, &q);

		s1 = (1 - p) * q;
		s2 = p * (1 - q) * q;

		printf("#%d %s\n", i,s1<s2?"YES":"NO");
	}
	return 0;
}