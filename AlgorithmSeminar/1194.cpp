#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef struct { int x, y; }point;
int n, m, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 },answer= INF;
string arr[51];
queue<pair<point, int>> q;
bool visit[33][51][51];

bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			if (arr[i][j] == '0') {
				point s = { j,i };
				q.push(make_pair(s, 0));
				visit[0][i][j] = 1;
			}
	}

	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			auto x = q.front(); q.pop();
			point cur = x.first;

			if (arr[cur.y][cur.x] == '1') {
				answer = time; 
				printf("%d", time);
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i];
				if (!safe(nx, ny) || visit[x.second][ny][nx])continue;
				int key = x.second;
				bool b = false;

				switch (arr[ny][nx]) {
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
					key |= 1 << (arr[ny][nx] - 'a'); b = true;
					break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
					if ((key >> (arr[ny][nx] - 'A') & 1) == 1) {
						b = true;
					}
					break;
				case '.':
				case '1':
				case '0':
					b = true;
					break;
				case '#':
					break;
				default:
					break;
				}

				if (b) {
					visit[key][ny][nx] = true;
					point next = { nx,ny };
					q.push(make_pair(next, key));
				}
			}
		}
		time++;
	}
	printf("%d", answer == INF ? -1 : answer);
	return 0;
}