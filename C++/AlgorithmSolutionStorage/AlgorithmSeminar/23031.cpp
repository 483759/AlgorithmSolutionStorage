#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
	int x, y, d;
}point;

int n, light[16][16], dx[] = { 1,0,-1,0,1,1,-1,-1,0 }, dy[] = { 0,1,0,-1,1,-1,1,-1,0 };
string a, board[16];
vector<point> zombi;

bool safe(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

bool findLocker() {

	point cur = { 0,0,1 };
	for (char x : a) {
		if (x == 'F') {
			int nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
			if (safe(nx, ny)) {
				cur = { nx,ny,cur.d };
			}
			if (board[cur.y][cur.x] == 'S') {
				for (int i = 0; i < 9; i++) {
					nx = cur.x + dx[i]; ny = cur.y + dy[i];
					if(safe(nx,ny)) light[ny][nx] = 1;
				}
			}
		}
		else {
			cur.d = (x == 'R') ? (cur.d + 1) % 4 : (cur.d + 3) % 4;
		}

		for (auto z : zombi) {
			if (light[cur.y][cur.x] != 1 && board[cur.y][cur.x] != 'S' && cur.x == z.x && cur.y == z.y)
				return true;
		}

		for (int i = 0; i < zombi.size(); i++) {
			point& z = zombi[i];
			int nx = z.x + dx[z.d], ny = z.y + dy[z.d];
			if (!safe(nx, ny)) {
				z.d = (z.d + 2) % 4;
			}
			else {
				z = { nx,ny,z.d };
				if (light[z.y][z.x] != 1 && board[z.y][z.x] != 'S' && (z.x == cur.x && z.y == cur.y)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	cin >> a;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'Z')
				zombi.push_back({ j,i,1 });
		}
	}

	bool ret = findLocker();
	if (ret)cout << "Aaaaaah!";
	else cout << "Phew...";
	return 0;
}