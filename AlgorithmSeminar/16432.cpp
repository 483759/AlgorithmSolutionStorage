#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> op;
int n, dp[1005][1005];
bool check,visit[1005][1005];

void dfs(int dep, int pre, vector<int> ddeok) {
	if (check)return;
	if (dep == 0) {
		while (!ddeok.empty()) {
			printf("%d\n", ddeok.back());
			ddeok.pop_back();
		}
		check = true;
		return;
	}

	visit[dep + 1][pre] = true;
	for (auto x : op[dep]) {
		if (x == pre||visit[dep][x])continue;
		ddeok.push_back(x);
		dfs(dep - 1, x, ddeok);
		ddeok.pop_back();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	fill(&dp[0][0], &dp[n + 3][n + 2], INF);

	op = vector<vector<int>>(n + 1);
	for (int i = 1, m; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0, k; j < m; j++) {
			scanf("%d", &k);
			op[i].push_back(k);
		}
	}

	dfs(n, -1, vector<int>());
	if (!check)printf("-1");
	return 0;
}