#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define INF 987654321
#define pip pair<int,point>
using namespace std;

typedef struct point{ int x, y; point(int x, int y) { this->x = x; this->y = y; } }point;
typedef struct {
	bool operator()(pip a, pip b) {
		return a.first > b.first;
	}
}cmp;

string board[1001];
int n, m, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };	//동남서북
int dist[1001][1001], score[] = { 1,5,1,5 };

bool safe(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n && board[y][x] != 'D';
}

int dijkstra(point s, point f) {
	priority_queue<pip, vector<pip>, cmp> pq;
	fill(&dist[0][0], &dist[n][m + 1], INF);

	dist[s.y][s.x] = 0;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cost = pq.top().first;
		point cur = pq.top().second; pq.pop();
		if (cost > dist[cur.y][cur.x])continue;
		if (cur.x == f.x && cur.y == f.y)return dist[cur.y][cur.x];

		if (board[cur.y][cur.x] == 'L') {	//현재 칸에 사다리
			int ny = cur.y - 1;

			if (safe(cur.x, ny) && (dist[ny][cur.x] > dist[cur.y][cur.x] + 5)) {
				dist[ny][cur.x] = dist[cur.y][cur.x] + 5;
				pq.push(make_pair(dist[ny][cur.x], point(cur.x,ny)));
			}
		}
		if (board[cur.y][cur.x] != 'X') {	//현재 칸 아래가 사다리(아래) or 양옆으로 갈 수 있을 때
			for (int i = 0; i < 3; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i];

				if (safe(nx, ny) && (dist[ny][nx] > dist[cur.y][cur.x] + score[i])) {
					if (i == 1 && board[ny][nx] != 'L')continue;
					dist[ny][nx] = dist[cur.y][cur.x] + score[i];
					pq.push(make_pair(dist[ny][nx], point(nx,ny)));
				}
			}
		}
		if (board[cur.y][cur.x] == 'X') {	//허공에서 추락
			int ny = cur.y + 1;

			while (safe(cur.x, ny) && board[ny][cur.x] == 'X')
				ny++;

			if (safe(cur.x, ny) && (dist[ny][cur.x] > dist[cur.y][cur.x] + 10)) {
				dist[ny][cur.x] = dist[cur.y][cur.x] + 10;
				pq.push(make_pair(dist[ny][cur.x], point(cur.x,ny)));
			}
		}

	}
	return dist[f.y][f.x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);

	point s = { 0,0 }, f = { 0,0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'C')
				s = { j,i };
			if (board[i][j] == 'E')
				f = { j,i };
		}
	}

	int ans = dijkstra(s, f);
	if (ans == INF)cout << "dodo sad";
	else cout << ans;
	return 0;
}