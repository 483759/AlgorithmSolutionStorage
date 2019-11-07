#include <cstdio>
int n, m;
char mw[1001];
int map[1001][1001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%c", &mw[i]);
	for (int i = 0,u,v,d; i < m; i++) {
		scanf("%d%d%d", &u, &v, &d);
		map[u][v] = d; map[v][u] = d;
	}
	return 0;
}