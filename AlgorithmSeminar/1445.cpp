#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define pip pair<int,point>
#define INF 987654321
#define garbage 50000
#define size 55
using namespace std;

typedef struct { int x, y; }point;
typedef struct {
	bool operator()(pip a, pip b) {
		return a.first > b.first;
	}
}cmp;

int map[size][size];
int n, m;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

pair<int,int> dijkstra(point src,point snk) {
	int dist[size][size];
	point prev[size][size];
	bool visit[size][size] = { 0 };
	point nil = { -1,-1 };
	priority_queue<pip, vector<pip>, cmp> pq;

	fill(&dist[0][0], &dist[n + 1][m], INF);
	fill(&prev[0][0], &prev[n + 1][m], nil);
	
	dist[src.y][src.x] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		point cur = pq.top().second;
		pq.pop();
		if (visit[cur.y][cur.x])continue;

		visit[cur.y][cur.x] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (!safe(nx, ny)||visit[ny][nx])continue;
			if (dist[cur.y][cur.x] + map[ny][nx] < dist[ny][nx]) {
				dist[ny][nx] = dist[cur.y][cur.x] + map[ny][nx];
				point next = { nx,ny };
				pq.push(make_pair(dist[ny][nx], next));
				prev[ny][nx] = cur;
			}
		}
	}

	pair<int, int> cost=make_pair(0,0);
	point path = prev[snk.y][snk.x];
	while (!(path.x == -1 && path.y == -1)) {
		int c = map[path.y][path.x];
		if (c == 1)cost.second++;
		else if (c == garbage)cost.first++;
		path = prev[path.y][path.x];
	}

	return cost;
}

int main() {
	freopen("input.txt", "r", stdin);

	point src, snk;
	cin >> n >> m;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			switch (c) {
			case 'g':
				map[i][j] = garbage;
				break;
			case 'S':
				src = { j,i };
				break;
			case 'F':
				snk = { j,i };
				break;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != garbage)continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k], ny = i + dy[k];
				if (!safe(nx, ny) || map[ny][nx])continue;
				map[ny][nx] = 1;
			}
		}

	map[src.y][src.x] = map[snk.y][snk.x] = 0;

	pair<int, int> ans = dijkstra(src, snk);
	cout << ans.first << " " << ans.second;
	return 0;
}