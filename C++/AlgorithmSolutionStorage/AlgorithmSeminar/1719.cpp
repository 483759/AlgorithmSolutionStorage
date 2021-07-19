#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;

int n, m;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

	for (int i = 0, u, v, w; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = w;
		dist[v][u] = w;
		map[u][v] = v;
		map[v][u] = u;
	}

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		map[i][i] = i;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					map[i][j] = map[i][k];
				}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)printf("- ");
			else printf("%d ", map[i][j]);
		}			
		printf("\n");
	}
	return 0;
}