#include <iostream>

#include <string>
#include <vector>
#include <queue>
#define n 5

using namespace std;

typedef struct { int x, y; }point;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

int bfs(vector<string> v) {
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 'P')continue;

			bool visit[n][n] = { 0 };
			queue<point> q;
			q.push({ j,i });
			visit[i][j] = true;

			for (int k = 0; k < 2; k++) {
				int size = q.size();
				while (size--) {
					point cur = q.front(); q.pop();

					for (int d = 0; d < 4; d++) {
						int nx = cur.x + dx[d], ny = cur.y + dy[d];
						if (!safe(nx, ny) || visit[ny][nx] || v[ny][nx] == 'X')continue;
						if (v[ny][nx] == 'P')
							return 0;
						q.push({ nx,ny });
						visit[ny][nx] = true;
					}
				}
			}
		}
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (auto p : places) {
		answer.push_back(bfs(p));
	}
	return answer;
}

int main() {
	vector<int> v= solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
	return 0;
}