#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, cnt, ans, m;
char map[13][7];
bool visit[13][7];
struct point { int x, y; };
queue<point> q;
queue<char> tmp;
bool safe(int x, int y) {
	return y >= 0 && y < 12 && x >= 0 && x < 6;
}
int bfs(point p, char o) {
	visit[p.y][p.x] = true;
	q.push(p); cnt = 1;
	while (!q.empty()) {
		point cp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cp.x + dx[i], ny = cp.y + dy[i];
			if (map[ny][nx] == o && safe(nx, ny) && !visit[ny][nx]) {
				visit[ny][nx] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	for (int i = 0; i < 12; i++) {
		scanf(" %c", &map[i][0]);
		for (int j = 1; j < 6; j++)
			scanf("%c", &map[i][j]);
	}
	do {
		m = 0;
		for (int i = 0, cnt = 0; i < 12; i++)
			for (int j = 0; j < 6; j++) {
				memset(visit, false, sizeof(visit));
				if (map[i][j] != '.' && !visit[i][j]) {
					cnt = bfs({ j,i }, map[i][j]);
					m = cnt > m ? cnt : m;
				}
				if (cnt >= 4) {
					for (int a = 0; a < 12; a++)
						for (int b = 0; b < 6; b++)
							if (visit[a][b])map[a][b] = '.';
				}
			}
		for (int a = 0; a < 6; a++) {
			for (int b = 11; b >= 0; b--)
				if (map[b][a] != '.')
					tmp.push(map[b][a]);
			for (int b = 11; b >= 0; b--)
				if (!tmp.empty()) {
					map[b][a] = tmp.front(); tmp.pop();
				}
				else
					map[b][a] = '.';
		}
		if (m >= 4)ans++;
	} while (m >= 4);
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, cnt;
//char map[13][7];
//bool visit[13][7];
//struct point { int x, y; };
//queue<point> q;
//queue<char> tmp;
//bool safe(int x, int y) {
//	return y >= 0 && y < 12 && x >= 0 && x < 6;
//}
//int bfs(point p, char o) {
//	visit[p.y][p.x] = true;
//	q.push(p); cnt = 1;
//	while (!q.empty()) {
//		point cp = q.front(); q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = cp.x + dx[i], ny = cp.y + dy[i];
//			if (map[ny][nx] == o && safe(nx, ny) && !visit[ny][nx]) {
//				visit[ny][nx] = true;
//				q.push({ nx,ny });
//				cnt++;
//			}
//		}
//	}
//	return cnt;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int i = 0; i < 12; i++) {
//		scanf(" %c", &map[i][0]);
//		for (int j = 1; j < 6; j++)
//			scanf("%c", &map[i][j]);
//	}
//
//	for (int i = 0, cnt = 0; i < 12; i++)
//		for (int j = 0; j < 6; j++) {
//			memset(visit, false, sizeof(visit));
//			if (map[i][j] != '.' && !visit[i][j]) {
//				cnt = bfs({ j,i }, map[i][j]);
//				printf("%c, %d\n", map[i][j], cnt);
//			}
//			if (cnt >= 4) {
//				for (int a = 0; a < 12; a++)
//					for (int b = 0; b < 6; b++)
//						if (visit[a][b])map[a][b] = '.';
//
//				for (int a = 0; a < 6; a++) {
//					for (int b = 11; b >= 0; b--)
//						if (map[b][a] != '.')
//							tmp.push(map[b][a]);
//					for (int b = 11; b >= 0; b--)
//						if (!tmp.empty()) {
//							map[b][a] = tmp.front(); tmp.pop();
//						}
//						else
//							map[b][a] = '.';
//				}
//			}
//		}
//	for (int i = 0, cnt = 0; i < 12; i++) {
//		for (int j = 0; j < 6; j++)
//			printf("%c", map[i][j]);
//		printf("\n");
//	}
//
//	return 0;
//}