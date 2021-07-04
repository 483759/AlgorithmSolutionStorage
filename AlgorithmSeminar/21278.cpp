#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dist[105][105];
int n, m,a,b,ans=INF;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	fill(&dist[0][0], &dist[n + 2][n + 1], INF);

	for (int i = 0,a,b; i < m; i++) {
		scanf("%d%d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	floyd();
	for(int i=1;i<=n;i++)
		for (int j = i+1; j <= n; j++) {
			int sum = 0;

			for (int k = 1; k <= n; k++)
				sum += min(dist[i][k], dist[j][k])*2;
			if (sum < ans) {
				a = i; b = j; ans = sum;
			}
		}
	printf("%d %d %d",a,b,ans);
	return 0;
}