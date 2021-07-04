#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n, m, r, ans;
vector<int> item;
vector<vector<int>> dist;

int main() {
	scanf("%d%d%d", &n, &m, &r);
	item = vector<int>(n+1);
	dist = vector<vector<int>>(n + 1);

	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &item[i]);
		dist[i] = vector<int>(n + 1, 99999);
		dist[i][i] = 0;
	}

	for (int i = 0,a,b,l; i < r; i++) {
		scanf("%d%d%d", &a, &b, &l);
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; i++) {
		int sum = 0;

		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m)sum += item[j];
		}
		ans = max(ans, sum);
	}

	printf("%d", ans);

	return 0;
}