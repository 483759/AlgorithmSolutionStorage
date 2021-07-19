#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef struct { int x, y; }point;
int r, c, map[105][105], n, s, dir = -1;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[105][105], cluster[105][105];
char m[105][105];
void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)printf("%c", map[i][j]?'x':'.');
		printf("\n");
	}
}bool safe(int x, int y) { return x >= 0 && x < c && y >= 0 && y <= r; }
bool bfs() {
	memset(visit, 0, sizeof(visit));
	memset(cluster, 0, sizeof(cluster));
	visit[r][0] = 1;
	queue<point> q;
	q.push({ 0,r });
	while (!q.empty()) {
		point cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (!safe(nx, ny) || !map[ny][nx] || visit[ny][nx])continue;
			visit[ny][nx] = 1;
			q.push({ nx,ny });
		}
	}bool b = 0;
	for (int i = 0; i <= r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] && !visit[i][j]) {
				cluster[i][j] = 1; b = 1;
			}return b;
}
int reach() {
	int k = 0;
	bool temp[105][105]; memcpy(temp, cluster, sizeof(cluster));
	while (k++ <= r) {
		for(int i=r-1;i>=0;i--)
			for (int j = 0; j < c; j++) 
			if(temp[i][j]){
				if (visit[i + 1][j])return k-1;
				temp[i + 1][j] = 1;
				temp[i][j] = 0;
			}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)scanf("%s", m[i]);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)if (m[i][j] == 'x')map[i][j] = 1;
	for (int j = 0; j < c; j++)map[r][j] = 1;
	scanf(" %d", &n);
	while (n--) {
		dir *= -1;
		scanf("%d", &s); s = r - s;
		int cur = (dir == 1) ? 0 : c - 1;
		while (safe(cur, s) && !map[s][cur])cur += dir;
		if (!safe(cur, s))continue;
		map[s][cur] = 0; bool b = 0; 
		b=bfs();
		int h = 0;
		if (!b)continue; h = reach();
		for (int i = r; i >=0; i--)
			for (int j = 0; j < c; j++)
				if (cluster[i][j]) {
					map[i][j] = 0;
					map[i + h][j] = 1;
				}
	}
	print();
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int r, c, n, d = 1, cr, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//char map[101][101];
//bool visit[101][101];
//void dfs(int r, int c) {
//	visit[r][c] = true;
//	for (int next = 0; next < 4; next++)
//		if (!visit[r + dy[next]][c + dx[next]] && map[r + dy[next]][c + dx[next]] == 'x')
//			dfs(r + dy[next], c + dx[next]);
//}
//bool isfloat() {
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//			if (map[i][j] == 'x' && !visit[i][j])return true;
//	return false;
//}
//int main() {
//	scanf("%d%d", &r, &c);
//	for (int i = 0; i < r; i++) {
//		scanf(" %c", &map[i][0]);
//		for (int j = 1; j < c; j++)
//			scanf("%c", &map[i][j]);
//	}
//	for (int j = 0; j < c; j++)map[r][j] = 'x';
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int min = 1001;
//		memset(visit, false, sizeof(visit));
//		scanf("%d", &cr); cr = r - cr;
//		int j = (d > 0) ? 0 : c - 1;
//		while (map[cr][j] != 'x' && j<c) j += d;
//		map[cr][j] = '.';
//		dfs(r, 0);
//		if (isfloat()) {
//			for (int k = 0; k < c; k++)
//				for (int l = 0, cl = -1; l <= r; l++) {
//					if (map[l][k] == 'x' && !visit[l][k]) cl = l;
//					else if (map[l][k] == 'x' && visit[l][k] && cl != -1) {
//						if (l - cl < min)min = l - cl;
//						break;
//					}
//				}
//		}
//		for (int k = c - 1; k >= 0; k--)
//			for (int l = r - 1; l >= 0; l--)
//				if (map[l][k] == 'x' && !visit[l][k]) {
//					map[l + min - 1][k] = 'x';
//					map[l][k] = '.';
//				}
//		d *= -1;
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
//using namespace std;
//int r, c, n, d = 1, cr, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//char map[101][101];
//bool visit[101][101];
//void dfs(int r, int c) {
//	visit[r][c] = true;
//	for (int next = 0; next < 4; next++)
//		if (!visit[r + dy[next]][c + dx[next]] && map[r + dy[next]][c + dx[next]] == 'x')
//			dfs(r + dy[next], c + dx[next]);
//}
//bool isfloat() {
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//			if (map[i][j] == 'x' && !visit[i][j])return true;
//	return false;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &r, &c);
//	for (int i = 0; i < r; i++) {
//		scanf(" %c", &map[i][0]);
//		for (int j = 1; j < c; j++)
//			scanf("%c", &map[i][j]);
//	}
//	for (int j = 0; j < c; j++)map[r][j] = 'x';
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int min = 1001;
//		memset(visit, false, sizeof(visit));
//		scanf("%d", &cr); cr = r - cr;
//		int j = (d > 0) ? 0 : c - 1;
//		while (map[cr][j] != 'x' && j<c) j += d;
//		map[cr][j] = '.';
//		dfs(r, 0);
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++)
//				printf("%c", map[i][j]);
//			printf("\n");
//		}
//		if (isfloat()) {
//			for (int k = 0; k < r; k++) {
//				for (int l = 0; l < c; l++)
//					printf("%c", visit[k][l] ? 'x' : '.');
//				printf("\n");
//			}
//			printf("\n");
//			for (int i = 0; i < r; i++) {
//				for (int j = 0; j < c; j++)
//					printf("%c", map[i][j]);
//				printf("\n");
//			}
//			printf("\n");
//
//			for (int k = 0; k < c; k++)
//				for (int l = 0, cl = -1; l <= r; l++) {
//					if (map[l][k] == 'x' && !visit[l][k]) cl = l;
//					else if (map[l][k] == 'x' && visit[l][k] && cl != -1) {
//						if (l - cl < min)min = l - cl;
//						printf("%d %d %d\n", l, cl, k);
//						break;
//					}
//				}
//			printf("%d\n", min);
//		}
//		for (int k = c-1; k >=0; k--)
//			for (int l = r-1; l >= 0; l--)
//				if (map[l][k] == 'x' && !visit[l][k]) {
//					map[l + min-1][k] = 'x';
//					map[l][k] = '.';
//				}
//		d *= -1;
//	}
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++)
//			printf("%c", map[i][j]);
//		printf("\n");
//	}
//	return 0;
//}