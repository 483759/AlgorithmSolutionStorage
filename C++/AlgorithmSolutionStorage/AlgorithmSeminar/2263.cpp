#include <cstdio>

int n, order[2][100001];

void solve(int il, int ir, int pl, int pr) {
	if (il > ir)return;
	int root = order[1][pr];	//postorder¿« right
	printf("%d ", root);
	if (il == ir)return;
	int idx = 0;
	for (idx = il; idx <= ir; idx++)
		if (order[0][idx] == root)break;
	//idx-il = size
	solve(il, idx - 1, pl, pl + idx - il - 1);
	solve(idx + 1, ir, pl + idx - il, pr - 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < n; i++) {
			scanf("%d", &order[j][i]);
		}
	solve(0, n - 1, 0, n - 1);
}