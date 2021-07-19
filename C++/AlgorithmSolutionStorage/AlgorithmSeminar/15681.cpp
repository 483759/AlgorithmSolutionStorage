#include <cstdio>
#include <vector>
using namespace std;

int n, r, q,dp[100005];
vector<int> node[100005],tree[100005];

void makeTree(int cur, int parent) {
	for (int next : node[cur])
		if (next != parent) {
			tree[cur].push_back(next);
			makeTree(next, cur);
		}
}

void countSubtreeNodes(int cur) {
	dp[cur] = 1;
	for (int next : tree[cur]) {
		countSubtreeNodes(next);
		dp[cur] += dp[next];
	}
}

int main() {
	scanf("%d%d%d", &n, &r, &q);
	for (int i = 0, u, v; i < n - 1; i++) {
		scanf("%d%d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	makeTree(r, -1); countSubtreeNodes(r);
	while (q--) {
		int u;
		scanf("%d", &u);
		printf("%d\n", dp[u]);
	}
	return 0;
}