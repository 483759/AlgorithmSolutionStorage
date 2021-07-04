#include <cstdio>
#include <algorithm>
int n, m,arr[8], idx,ans[8];
bool b[10001];
void dfs(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < idx; i++) {
		if (dep && arr[i] < ans[dep - 1])continue;
		ans[dep] = arr[i];
		dfs(dep + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,k; i < n; i++) {
		scanf("%d", &k);
		if (b[k])continue;
		b[k] = 1;
		arr[idx++] = k;
	}
	std::sort(arr, arr + idx);
	dfs(0);
	return 0;
}