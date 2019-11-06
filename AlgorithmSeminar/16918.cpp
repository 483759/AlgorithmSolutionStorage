#include <cstdio>
#include <algorithm>
#include <queue>
#define safe(x,y) (x) >= 0 && (x) < c && (y) >= 0 && (y) < r
using namespace std;
int r, c, n, t;
int map[2][205][205], dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
char chr;
struct point { int x, y; };
queue<point> q;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &r, &c, &n);
	scanf(" ");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &chr);
			if (chr == 'O') {
				map[0][i][j] = 1;
				map[1][i][j] = 2;
			}
		}
		scanf(" ");
	}t = 1;
	while (n != t++) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (map[0][i][j]) {
					map[1][i][j]--;
					if (!map[1][i][j])q.push({ j,i });
				}
		if (t % 2) {
			while (!q.empty()) {
				point cur = q.front(); q.pop();
				map[0][cur.y][cur.x] = map[1][cur.y][cur.x] = 0;
				for (int k = 0, nx, ny; k < 4; k++) {
					nx = cur.x + dx[k]; ny = cur.y + dy[k];
					if (safe(nx, ny)) {
						map[0][ny][nx] = 0;
						map[1][ny][nx] = 0;
					}
				}
			}
		}
		else {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (!map[0][i][j]) {
						map[0][i][j] = 1;
						map[1][i][j] = 3;
					}
		}
	}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				printf("%c", map[0][i][j] ? 'O' : '.');
			printf("\n");
		}
	return 0;
}
/*
3 4 11
.O..
O...
.O..
*/
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//int r, c, n, t, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
//char chr, map[205][205];
//struct b { int x, y, t; };
//queue<b> q;
//bool safe(int x, int y) {
//	return x >= 0 && x < c && y >= 0 && y < r;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &r, &c, &n);
//	scanf(" ");
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			scanf("%c", &chr);
//			map[i][j] = chr;
//			if (chr == 'O') {
//				q.push({ j,i,1 });
//			}
//		}
//		scanf(" ");
//	}t = 1;
//	while (n != t++) {
//		for (int i = q.size(); i > 0; i--) {
//			b cur = q.front(); q.pop();
//			if (cur.t) {
//				cur.t--;
//				q.push(cur);
//			}
//			else if (t % 2) {
//				map[cur.y][cur.x] = '.';
//				for (int i = 0, nx, ny; i < 4; i++) {
//					nx = cur.x + dx[i]; ny = cur.y + dy[i];
//					if (safe(nx, ny)
//						&& map[ny][nx] == 'O') {
//						map[ny][nx] = '.';
//					}
//				}
//			}
//		}
//		if (!(t % 2))
//			for (int i = 0; i < r; i++)
//				for (int j = 0; j < c; j++)
//					if (map[i][j] == '.') {
//						q.push({ j,i,2 });
//						map[i][j] = 'O';
//					}
//	}
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++)
//			printf("%c", map[i][j]);
//		printf("\n");
//	}
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//int r, c, n, t,dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
//char chr, map[2][205][205];
//struct p { int x, y; };
//queue<p> q;
//bool safe(int x, int y) {
//	return x >= 0 && x < c && y >= 0 && y < r;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	fill(&map[1][0][0], &map[1][200][200], 100);
//	scanf("%d%d%d", &r, &c, &n);
//	scanf(" ");
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			scanf("%c", &chr);
//			map[0][i][j] = chr;
//			if (chr=='O') { 
//				q.push({ j,i }); 
//				map[1][i][j] = 0;
//			}
//		}
//		scanf(" ");
//	}t = 1;
//	q.push({ -1,-1 });
//	while (n!=t++) {
//		if (t % 2) {
//			while (!q.empty()) {
//				p cur = q.front(); q.pop();
//				if (cur.x == -1 && cur.y == -1)break;
//				if (map[1][cur.y][cur.x] + 3 == t) {
//					map[0][cur.y][cur.x] = '.';
//					for (int i = 0, nx, ny; i < 4; i++) {
//						nx = cur.x + dx[i]; ny = cur.y + dy[i];
//						if (safe(nx, ny) 
//							&& map[0][ny][nx] == 'O'
//							&&map[1][ny][nx]!=map[1][cur.y][cur.x]) {
//							map[0][ny][nx] = '.';
//							map[1][ny][nx] = -10;
//						}
//					}
//				}
//			}
//		}
//		else {
//			for (int i = 0; i < r; i++)
//				for (int j = 0; j < c; j++)
//					if (map[0][i][j] == '.') {
//						q.push({ j,i });
//						map[0][i][j] = 'O';
//						map[1][i][j] = t;
//					}
//			q.push({ -1,-1 });
//		}
//	}
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++)
//			printf("%c", map[0][i][j]);
//		printf("\n");
//	}
//	return 0;
//}