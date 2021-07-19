#include <cstdio>
#define max(a,b) a>b?a:b
int n, a,b,m;
int main() {
	scanf("%d", &n);
	scanf("%d", &a);
	for (int i = 1; i < n; i++) {
		scanf("%d", &b);
		m = max(!a&b, m);
		a = b;
	}
	printf("%d", m);
	return 0;
}