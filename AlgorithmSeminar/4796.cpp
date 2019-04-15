#include <cstdio>

int main() {
	int l, p, v, cnt = 0, i=1;

	while (1) {
		scanf("%d %d %d", &l, &p, &v);
		if (!l && !p && !v)
			return 0;

		cnt = (int)(v / p)*l;
		cnt += (v%p) < l ? (v % p) : l;

		printf("Case %d: %d\n", i++, cnt);
	}
	return 0;
}