#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define pip pair<int,point>
using namespace std;

typedef struct {
	int x, y;
}point;

int n, tc, ans, dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = { 1,0,-1,-1,-1,0,1,1 };
string map[301];

struct compare {
	bool operator()(pip a, pip b) {
		return a.first > b.first;
	}
};

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

void print() {
	for (int i = 0; i < n; i++)
		cout << map[i] << '\n';
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> n; ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		bool visit[301][301] = { 0 };
		priority_queue< pip, vector<pip>, compare > pq;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '*')continue;
				int t = 0;
				for (int k = 0; k < 8; k++) {
					int nx = j + dx[k], ny = i + dy[k];
					if (safe(nx, ny) && map[ny][nx] == '*')
						t++;
				}
				map[i][j] = t + '0';
				point p = { j,i };
				pq.push(make_pair(t, p));
			}
		while (!pq.empty()) {
			auto cur = pq.top().second; pq.pop();
			if (visit[cur.y][cur.x])continue;

			ans++;
			visit[cur.y][cur.x] = true;
			if (map[cur.y][cur.x] != '0')continue;
			queue<point> q;
			q.push(cur);

			while (!q.empty()) {
				point p = q.front(); q.pop();

				for (int i = 0; i < 8; i++) {
					int nx = p.x + dx[i], ny = p.y + dy[i];
					if (!safe(nx, ny) || visit[ny][nx] || map[ny][nx] == '*')continue;
					visit[ny][nx] = true;
					if (map[ny][nx] == '0')
						q.push({ nx,ny });
				}
			}
		}
		cout << "#"<<T<<" "<<ans<<'\n';
	}
	return 0;
}