#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

typedef struct { int x, y; }point;
point map[105];
int t, n;
int dist[105][105];

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		n += 2;
		fill(&dist[0][0], &dist[n + 1][n], INF);
		for (int i = 0, x, y; i < n; i++) {
			scanf("%d%d", &map[i].x, &map[i].y);
			dist[i][i] = 0;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				dist[i][j] = abs(map[i].x - map[j].x) + abs(map[i].y - map[j].y);
				if (dist[i][j] > 1000)dist[i][j] = INF;
			}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {

					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
				}

		printf("%s\n", dist[0][n - 1] == INF ? "sad" : "happy");
	}
	return 0;
}

//#include <cstdio>
//#include <queue>
//#include <memory.h>
//#define abs(x,y) (((x-y)>0)?(x-y):(y-x))
//using namespace std;
//int n,t;
//struct point { int x, y; };
//point ds[101], s, f, cur;
//bool visit[101];
//queue<point> q;
//bool touch(point p1,point p2) {
//	return abs(p1.x, p2.x) + abs(p1.y, p2.y) <= 1000;
//}
//void bfs() {
//	while (!q.empty()) {
//		cur = q.front(); q.pop();
//		for (int i = 0; i < n; i++) {
//			if (!visit[i]&&touch(cur,ds[i])) {
//				q.push({ ds[i].x,ds[i].y });
//				visit[i] = true;
//			}
//			if (touch(cur, f)) {
//				printf("happy\n");
//				return;
//			}
//		}
//	}
//	printf("sad\n");
//}
//int main() {
//	scanf("%d", &t);
//	for (int j = 0; j < t; j++) {
//		scanf("%d", &n);
//		scanf("%d%d", &s.x, &s.y);
//		for (int i = 0; i < n; i++)scanf("%d%d", &ds[i].x, &ds[i].y);
//		scanf("%d%d", &f.x, &f.y);
//		q.push(s);
//		bfs();
//		memset(visit, false, sizeof(visit));
//		while (!q.empty())q.pop();
//	}
//	return 0;
//}