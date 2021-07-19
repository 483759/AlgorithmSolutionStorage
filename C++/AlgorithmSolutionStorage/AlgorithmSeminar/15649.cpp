#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, v[9];
void func(int d) {
	if (d > m) {
		for (int i : v)
			if (i)printf("%d ", i);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[d])continue;
		v[d] = i;
		func(d + 1);
		v[d] = 0;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	func(1);
	return 0;
}