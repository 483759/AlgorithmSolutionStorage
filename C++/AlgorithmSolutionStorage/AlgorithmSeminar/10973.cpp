#include <cstdio>
int n, arr[10001], num,t;
bool chk[10001];
void dfs(int dep) {
	if (dep > n) {
		int k = 0;
		for (int i = n; i > 0; i--) {
			k *= 10; k += arr[i];
		}
		if (k == num) {
			printf("%d", t);
			return;
		}
		t = k;
		return;
	}

	for (int i = dep; i <= n; i++) {
		if (chk[i])continue;
		chk[i] = 1;
		arr[dep] = i;
		dfs(dep + 1);
		chk[i] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0, d; i < n; i++) {
		scanf("%d", &d);
		num *= 10; num += d;
	}
	dfs(1);
	return 0;
}