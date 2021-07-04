#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define pip pair<int,point>
#define INF 987654321

using namespace std;

typedef struct point {
	int x, y, d;
	point(int _x, int _y, int _d) :x(_x), y(_y), d(_d) {};
}point;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

struct cmp {
	bool operator()(pip a, pip b) {
		return a.first > b.first;
	}
};

bool safe(int x, int y, int n) { return x >= 0 && x < n && y >= 0 && y < n; }

void print(vector<vector<int>> map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			printf("%4d ", map[i][j]==INF?-1:map[i][j]);
		printf("\n");
	}
}


int dijkstra(vector<vector<int>> board) {
	int n = board.size();
	vector<vector<vector<int>>> dist(4);
	vector<vector<vector<bool>>> visit(4);

	for (int i = 0; i < 4; i++) {
		visit[i] = vector<vector<bool>>(n);
		dist[i] = vector<vector<int>>(n);
		for (int j = 0; j < n; j++) {
			visit[i][j] = vector<bool>(n, false);
			dist[i][j] = vector<int>(n, INF);
		}
	}


	priority_queue <pip, vector<pip>, cmp> pq;
	pq.push(make_pair(0, point(0,0,0)));
	pq.push(make_pair(0, point(0,0,1)));
	dist[0][0][0] = 0;
	dist[1][0][0] = 0;

	while (!pq.empty()) {
		auto cur = pq.top().second; pq.pop();

		if (visit[cur.d][cur.y][cur.x])continue;
		visit[cur.d][cur.y][cur.x] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (!safe(nx, ny, n) || board[ny][nx])continue;
			if ((i%2)==(cur.d%2)) {
				if (dist[i][ny][nx] > dist[cur.d][cur.y][cur.x] + 100) {
					dist[i][ny][nx] = dist[cur.d][cur.y][cur.x] + 100;
					pq.push(make_pair(dist[i][ny][nx], point(nx, ny, i)));
				}
			}
			else {
				if (dist[i][ny][nx] > dist[cur.d][cur.y][cur.x] + 600) {
					dist[i][ny][nx] = dist[cur.d][cur.y][cur.x] + 600;
					pq.push(make_pair(dist[i][ny][nx], point(nx, ny, i)));
				}
			}
		}
		
	}

	//print(dist);
	int min = INF;
	for (int i = 0; i < 4; i++)min = dist[i][n - 1][n - 1] < min ? dist[i][n - 1][n - 1] : min;
	return min;
}

int solution(vector<vector<int>> board) {
	return dijkstra(board);
}

int main() {
	vector<vector<int>> v = { {0,0,0},{0,0,0},{0,0,0} };

	//{ {0,0,0},{0,0,0},{0,0,0} };
	//{{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};

	//{ {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0} };

	cout << solution(v);
}

//#include <string>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <iostream>
//using namespace std;
//
//typedef struct { int x, y, c, d, m; }road;
//
//int ans = 987654321, n, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool visit[26][26][626][4];
//
//bool safe(int x, int y) {
//	return x >= 0 && x < n && y >= 0 && y < n;
//}
//
//int solution(vector<vector<int>> board) {
//	n = board[0].size();
//	int count = n * n;
//
//	queue<road> q;
//	for (auto x : board)
//		for (auto y : x)if (y == 1)count--;
//	memset(visit[0][0], true, sizeof(visit[0][0]));
//
//	for (int i = 0; i <= 1; i++) {
//		if (safe(dx[i], dy[i]) && !board[dy[i]][dx[i]]) {
//			q.push({ dx[i],dy[i],0,i,1 });
//			visit[dy[i]][dx[i]][0][i] = 1;
//		}
//	}
//
//
//	while (!q.empty()) {
//		road cur = q.front(); q.pop();
//		if (cur.x == n - 1 && cur.y == n - 1) {
//			int k = cur.c * 500 + cur.m * 100;
//			if (k < ans)ans = k;
//			continue;
//		}
//		if ((cur.c * 500 + cur.m * 100 > ans) || cur.c > count)continue;
//
//		int nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
//		if (safe(nx, ny) && !visit[ny][nx][cur.c][cur.d] && !board[ny][nx]) {
//			q.push({ nx,ny,cur.c,cur.d,cur.m + 1 });
//			visit[ny][nx][cur.c][cur.d] = 1;
//		}
//
//		nx = cur.x + dx[(cur.d + 3) % 4], ny = cur.y + dy[(cur.d + 3) % 4];
//		if (safe(nx, ny) && !visit[ny][nx][cur.c][cur.d] && !board[ny][nx]) {
//			q.push({ nx,ny,cur.c + 1,(cur.d + 3) % 4,cur.m + 1 });
//			visit[ny][nx][cur.c + 1][(cur.d + 3) % 4] = 1;
//		}
//
//		nx = cur.x + dx[(cur.d + 1) % 4], ny = cur.y + dy[(cur.d + 1) % 4];
//		if (safe(nx, ny) && !visit[ny][nx][cur.c][cur.d] && !board[ny][nx]) {
//			q.push({ nx,ny,cur.c + 1,(cur.d + 1) % 4,cur.m + 1 });
//			visit[ny][nx][cur.c + 1][(cur.d + 1) % 4] = 1;
//		}
//	}
//	return ans;
//}
