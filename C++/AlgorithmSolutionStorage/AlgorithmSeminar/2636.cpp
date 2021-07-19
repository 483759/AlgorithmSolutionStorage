#include <cstdio>
int n, m, h, ans = -1;
int lad[35][15];

bool game() {
	for (int j = 1; j <= n; j++) {
		int cur = j;
		int row = 1;
		while (row <= h) {
			if (lad[row][cur]==1)cur++;
			else if (lad[row][cur]==2)cur--;
			row++;
		}
		if (cur != j)return false;
	}
	return true;
}

bool dfs(int idx, int dep, int k) {
	if (dep==k) {
		if (game())return true;
		return false;
	}

	for (int i = idx; i <= h; i++)
		for (int j = 1; j < n; j++)
		{
			if (lad[i][j] || lad[i][j + 1])continue;
			lad[i][j] = 1;
			lad[i][j + 1] = 2;
			if(dfs(i, dep+1, k))return true;
			lad[i][j] = 0;
			lad[i][j + 1] = 0;
		}
	return false;
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		lad[a][b] = 1;
		lad[a][b + 1] = 2;
	}
	for (int i = 0; i <= 3; i++) {
		if (dfs(1, 0, i)) {
			ans = i;
			break;
		}
	}
	printf("%d", ans != -1 ? ans : -1);
	return 0;
}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//typedef struct { int x, y; }point;
//int r, c, num, pre, time, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool cheeze[105][105];
//
//bool safe(int x, int y) { return x >= 0 && x < c && y >= 0 && y < r; }
//
//int main() {
//	scanf("%d%d", &r, &c);
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++) {
//			cin >> cheeze[i][j];
//			if (cheeze[i][j])num++;
//		}
//
//	while (num) {
//		queue<point> q;
//		bool visit[105][105] = { 0 };
//
//		q.push({ 0,0 });
//		visit[0][0] = true;
//
//		pre = num;
//		while (!q.empty()) {
//			point cur = q.front(); q.pop();
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.x + dx[i], ny = cur.y + dy[i];
//				if (!safe(nx, ny) || visit[ny][nx])continue;
//				if (!cheeze[ny][nx])q.push({ nx,ny });
//				else num--;
//				visit[ny][nx] = 1;
//			}
//		}
//
//		for (int i = 0; i < r; i++)
//			for (int j = 0; j < c; j++)
//				if (visit[i][j])cheeze[i][j] = 0;
//
//		time++;
//	}
//	printf("%d\n%d", time, pre);
//
//	return 0;
//}