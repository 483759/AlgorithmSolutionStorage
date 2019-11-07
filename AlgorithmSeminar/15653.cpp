#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, v[9], k[9];
bool b[9];
void func(int t, int d) {
	if (d > m) {
		for (int a : v)
			if (a)printf("%d ", a);
		printf("\n");
		return;
	}
	for (int i = t; i <= n; i++) {
		v[d] = k[i];
		func(i, d + 1);
		v[d] = 0;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, t; i <= n; i++)scanf("%d", &k[i]);
	sort(k + 1, k + n + 1);
	func(1, 1);
	return 0;
}