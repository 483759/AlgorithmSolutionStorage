#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define pip pair<int,point>
#define INF 987654321
using namespace std;

typedef struct { int x, y; }point;

vector<string> board;
bool visit[501][501];
int treeDist[501][501];
int n, m, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
point s, f;

bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

typedef struct {
	bool operator() (pip a, pip b) { return a.first < b.first; }
}cmp;

void bfs() {
	memset(visit, false, sizeof visit);
	queue<point> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == '+') {
				q.push({ j,i });
				visit[i][j] = 1;
				treeDist[i][j] = 0;
			}

	for (int time = 0; q.size(); time++) {
		int size = q.size();

		while (size--) {
			point cur = q.front(); q.pop();
			treeDist[cur.y][cur.x] = time;

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i];
				if (!safe(nx, ny) || visit[ny][nx])continue;
				if (treeDist[ny][nx] > time) {
					q.push({ nx,ny });
					visit[ny][nx] = 1;
				}
			}
		}
	}
}

int dijkstra() {
	priority_queue<pip, vector<pip>, cmp> pq;
	int ans = min(treeDist[s.y][s.x], treeDist[f.y][f.x]);

	memset(visit, false, sizeof visit);
	pq.push(make_pair(treeDist[s.y][s.x], s));

	while (!pq.empty()) {
		point cur = pq.top().second;
		int cost = pq.top().first;	pq.pop();

		if (visit[cur.y][cur.x])continue;
		ans = min(ans, cost);
		visit[cur.y][cur.x] = true;

		if (cur.x == f.x && cur.y == f.y)break;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (!safe(nx, ny) || visit[ny][nx])continue;

			point next = { nx,ny };
			pq.push(make_pair(treeDist[ny][nx], next));
		}
	}

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	fill(&treeDist[0][0], &treeDist[n][m + 1], INF);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		board.push_back(s);
	}

	bfs();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'V')s = { j,i };
			if (board[i][j] == 'J')f = { j,i };
		}
	cout << dijkstra();
	return 0;
}