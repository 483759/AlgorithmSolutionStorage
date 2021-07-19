#include <cstdio>
int n, m,ans=1,arr[1001][1001],dp[1001][1001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			dp[i][j] = arr[i][j];
		}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (arr[i][j] &&
				(arr[i - 1][j - 1] && arr[i][j - 1] && arr[i - 1][j])){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > ans)ans = dp[i][j];
			}
	printf("%d", ans * ans);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//#define INF 987654321
//int n, m,w[105][105],dist[105][105];
//void floydwarshall() {
//	memcpy(dist, w, sizeof(w));
//
//	for(int k=1;k<=n;k++)
//	for(int i=1;i<=n;i++)
//		for (int j = 1; j <= n; j++) {
//			if (dist[i][k] + dist[k][j] < dist[i][j])
//				dist[i][j] = dist[i][k] + dist[k][j];
//		}
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	fill(&w[0][0], &w[n + 1][n], INF);
//	for (int i = 0,a,b,c; i < m; i++) {
//		scanf("%d%d%d", &a, &b, &c);
//		if (w[a][b] > c)
//			w[a][b] = c;
//	}
//	memcpy(dist, w, sizeof(w));
//
//	for (int k = 1; k <= n; k++)
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++) {
//				if (i == j)dist[i][j] = 0;
//				if (dist[i][k] + dist[k][j] < dist[i][j])
//					dist[i][j] = dist[i][k] + dist[k][j];
//			}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", dist[i][j]!=INF?dist[i][j]:0);
//		printf("\n");
//	}
//
//	return 0;
//}