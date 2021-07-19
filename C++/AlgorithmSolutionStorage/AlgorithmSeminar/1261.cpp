#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
typedef struct { int x, y; }point;
int n, m,arr[101][101],dist[101][101];
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
struct compare {
	bool operator()(pair<int, point> a, pair<int, point> b) {
		return a.first < b.first;
	}
};
int dst() {
	fill(&dist[0][0], &dist[n - 1][m], INF);
	priority_queue<pair<int, point>, vector<pair<int, point>>, compare> pq;

	point f = { 0,0 };
	pq.push(make_pair(0,f));
	dist[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		point cur = pq.top().second;

		pq.pop();
		for (int i = 0; i < 4; i++) {
			point n = { cur.x + dx[i], cur.y + dy[i] };
			if (!safe(n.x, n.y))continue;
			int ncost = arr[n.y][n.x];

			if (dist[cur.y][cur.x] + ncost < dist[n.y][n.x]) {
				dist[n.y][n.x] = dist[cur.y][cur.x] + ncost;
				pq.push({ -dist[n.y][n.x],n });
			}
		}
	}
	return dist[n - 1][m - 1];
}
int main() {
	scanf("%d%d", &m,&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		scanf("%1d", &arr[i][j]);
	printf("%d", dst());
	return 0;
}