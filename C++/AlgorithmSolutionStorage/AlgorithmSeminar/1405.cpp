#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, m,indeg[32005];
vector<int> graph[32005];
queue<int> q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,a,b; i < m; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		indeg[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (!indeg[i])q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i : graph[cur])
			if (indeg[i]) {
				indeg[i]--;
				if (!indeg[i])q.push(i);
			}
	}
	return 0;
}
//#include <cstdio>
//#include <math.h>
//typedef struct {
//	int x, y;
//}point;
//bool visit[50][50];
//double ans, prob[4];
//int n, cnt, dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
//void func(point cur, int dep, double a) {
//	if (dep == n) {
//		ans += a;
//		return;
//	}
//
//	visit[cur.y][cur.x] = 1;
//	for (int i = 0; i < 4; i++) {
//		int nx = cur.x + dx[i], ny = cur.y + dy[i];
//		if (visit[ny][nx])continue;
//
//		func({ nx,ny }, dep + 1, a * prob[i]);
//	}
//	visit[cur.y][cur.x] = 0;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 0; i < 4; i++) {
//		double k;
//		scanf("%lf", &k);
//		prob[i] = (double)k / 100;
//	}
//	func({ 25,25 }, 0, 1);
//	printf("%.10lf", ans);
//	return 0;
//}