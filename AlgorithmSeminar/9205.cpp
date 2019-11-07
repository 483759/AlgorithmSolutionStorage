#include <cstdio>
#include <queue>
#include <memory.h>
#define abs(x,y) (((x-y)>0)?(x-y):(y-x))
using namespace std;
int n,t;
struct point { int x, y; };
point ds[101], s, f, cur;
bool visit[101];
queue<point> q;
bool touch(point p1,point p2) {
	return abs(p1.x, p2.x) + abs(p1.y, p2.y) <= 1000;
}
void bfs() {
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int i = 0; i < n; i++) {
			if (!visit[i]&&touch(cur,ds[i])) {
				q.push({ ds[i].x,ds[i].y });
				visit[i] = true;
			}
			if (touch(cur, f)) {
				printf("happy\n");
				return;
			}
		}
	}
	printf("sad\n");
}
int main() {
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		scanf("%d", &n);
		scanf("%d%d", &s.x, &s.y);
		for (int i = 0; i < n; i++)scanf("%d%d", &ds[i].x, &ds[i].y);
		scanf("%d%d", &f.x, &f.y);
		q.push(s);
		bfs();
		memset(visit, false, sizeof(visit));
		while (!q.empty())q.pop();
	}
	return 0;
}