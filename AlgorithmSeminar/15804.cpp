#include <cstdio>
struct bus {
	int t, p, c;
};
int n, m, cn, ct, fin, index;
bus b[101];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)scanf("%d%d", &b[i].t, &b[i].p);
	while (index < m) {
		ct++;
		for (int i = fin; i < fin + cn; i++) {
			b[i].p--;
			if (b[fin].p <=0 && b[i].p <= 0) { fin++; cn--; }
		}
		while (cn < n && ct >= b[index].t) {
			if (cn && b[fin + cn - 1].c == n)break;
			if (!cn)	b[index].c = 1;
			else b[index].c = b[fin + cn - 1].c + 1;
			index++; cn++;
		}
	}
	printf("%d", b[m - 1].c);
	return 0;
}