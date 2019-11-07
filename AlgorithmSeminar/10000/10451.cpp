#include <cstdio>
int t, n, p[1002], ans;
bool chk[1002];
void dfs(int node) {
	chk[node] = true;
	if (!chk[p[node]])
		dfs(p[node]);
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ans = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			chk[j] = false;
			scanf("%d", &p[j]);
		}
		for (int i = 1; i <= n; i++)
			if (!chk[i]) {
				dfs(i);
				ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}