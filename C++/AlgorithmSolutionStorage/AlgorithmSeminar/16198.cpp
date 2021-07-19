#include <cstdio>
#include <algorithm>
using namespace std;
int n, w[1001], ans;
bool chk[1001];
void func(int x, int dep) {
	if (dep == n - 2) {
		ans = x > ans ? x : ans;
		return;
	}
	for (int i = 1, p, r; i < n - 1; i++) {
		if (!chk[i])continue;
		p = i - 1; r = i + 1;
		chk[i] = 0;
		while (!chk[p])p--; while (!chk[r])r++;
		func(x + w[p] * w[r], dep + 1);
		chk[i] = 1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &w[i]);
	fill(chk, chk + n, true);
	func(0, 0);
	printf("%d", ans);
	return 0;
}