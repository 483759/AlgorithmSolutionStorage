#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> c;
int n, m;

void praise(int cur) {
	for (auto x : tree[cur]) {
		c[x] += c[cur];
		praise(x);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	tree = vector<vector<int>>(n + 1);
	c = vector<int>(n + 1, 0);

	for (int i = 1, p; i <= n; i++) {
		scanf("%d", &p);
		if (p != -1) tree[p].push_back(i);
	}

	for (int a = 0, i, w; a < m; a++) {
		scanf("%d%d", &i, &w);
		c[i] += w;
		//praise(i, w);
	}

	praise(1);
	for (int i = 1; i <= n; i++) {
		printf("%d ", c[i]);
	}
	return 0;
}