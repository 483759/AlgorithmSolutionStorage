#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct { int r, c; }point;

int r, c, t, dr[] = { 0,-1,0,1 }, dc[] = { 1,0,-1,0 };
string map[101];
bool visit[101][101];

bool safe(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}

int func(point cur, int dep) {
	if (dep > t)return 0;
	int sum = 0;
	if (map[cur.r][cur.c] == 'S') {
		sum = 1;
		map[cur.r][cur.c] = '.';
	}

	int k = 0;
	for (int i = 0; i < 4; i++) {
		int nr = cur.r + dr[i];
		int nc = cur.c + dc[i];

		if (!safe(nr, nc) || map[nr][nc] == '#')continue;
		int f = func({ nr,nc }, dep + 1);
		k = max(k, f);
	}

	if (sum != 0) {
		map[cur.r][cur.c] = 'S';
	}
	return sum + k;
}

int main() {
	cin >> r >> c >> t;
	point cur = { 0,0 };

	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++)
			if (map[i][j] == 'G')cur = { i,j };
	}
	cout << func(cur, 0);

	return 0;
}