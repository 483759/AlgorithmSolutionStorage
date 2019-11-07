#include <cstdio>
#include <queue>
using namespace std;
int k, w, h, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, hx[] = { 1,2,2,1,-1,-2,-2,-1 }, hy[] = { -2,-1,1,2,2,1,-1,2 };
bool map[201][201],visit[201][201];
struct point { int x, y; };
queue<point> q;
void bfs() {
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for(int )
	}
}
int main() {
	scanf("%d%d%d", &k, &w, &h);
	for (int i = 0; i < w; i++)for (int j = 0; j < h; j++)scanf("%d", &map[i][j]);

	return 0;
}