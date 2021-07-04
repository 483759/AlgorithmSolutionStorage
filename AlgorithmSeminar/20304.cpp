#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#define INF 987654321;
using namespace std;
typedef struct { int x, y; }point;

string map[101],op;
queue<point> q;
int r, c,arr[105][105],t;
int dx[] = { 0,-1,0,1,-1,0,1,-1,0,1 }, dy[] = { 0,1,1,1,0,0,0,-1,-1,-1 };
point cur;

bool safe(int x, int y) { return x >= 0 && x < c && y >= 0 && y < r; }

int main() {
	freopen("input.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'R')q.push({ j,i });
			if (map[i][j] == 'I')cur = { j,i };
		}
			
	}
	cin >> op;

	for (char chr : op) {
		int k = chr - '0';
		t++;

		cur.x += dx[k];
		cur.y += dy[k];	//아두이노 좌표 이동

		queue<point> ready;
		while (!q.empty()) {
			point m = q.front(),next; q.pop();
			if (m.x == cur.x && m.y == cur.y) {
				printf("kraj %d", t);
				return 0;
			}
			int dist = INF;

			for (int i = 1; i <= 9; i++) {	//아두이노가 다음에 이동할 좌표 선정
				int nx = m.x + dx[i], ny = m.y + dy[i];
				if (!safe(nx, ny))continue;
				int d = abs(cur.x - nx) + abs(cur.y - ny);
				if (d < dist) {
					dist = d;
					next = { nx,ny };
				}
			}

			if (next.x == cur.x && next.y == cur.y) {
				printf("kraj %d", t);
				return 0;
			}

			arr[next.y][next.x]++;		//다음 칸에 아두이노가 몇명있을지 계산
		}

		for(int i=0;i<r;i++)
			for (int j = 0; j < c; j++) {
				if (!arr[i][j])continue;

				if (arr[i][j] > 1) {
					arr[i][j] = 0; continue;
				}
				arr[i][j] = 0;
				q.push({ j,i });
			}
	}
	int board[105][105] = { 0 };
	board[cur.y][cur.x] = 1;
	while (!q.empty()) {
		board[q.front().y][q.front().x] = 2;
		q.pop();
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			if (board[i][j] == 0)printf(".");
			else if (board[i][j] == 1)printf("I");
			else printf("R");
		printf("\n");
	}

}