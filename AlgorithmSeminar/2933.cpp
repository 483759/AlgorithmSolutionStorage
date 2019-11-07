#include <cstdio>
#include <algorithm>
using namespace std;
int r, c, n, d = 1, cr, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
char map[101][101];
bool visit[101][101];
void dfs(int r, int c) {
	visit[r][c] = true;
	for (int next = 0; next < 4; next++)
		if (!visit[r + dy[next]][c + dx[next]] && map[r + dy[next]][c + dx[next]] == 'x')
			dfs(r + dy[next], c + dx[next]);
}
bool isfloat() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == 'x' && !visit[i][j])return true;
	return false;
}
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf(" %c", &map[i][0]);
		for (int j = 1; j < c; j++)
			scanf("%c", &map[i][j]);
	}
	for (int j = 0; j < c; j++)map[r][j] = 'x';
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int min = 1001;
		memset(visit, false, sizeof(visit));
		scanf("%d", &cr); cr = r - cr;
		int j = (d > 0) ? 0 : c - 1;
		while (map[cr][j] != 'x' && j<c) j += d;
		map[cr][j] = '.';
		dfs(r, 0);
		if (isfloat()) {
			for (int k = 0; k < c; k++)
				for (int l = 0, cl = -1; l <= r; l++) {
					if (map[l][k] == 'x' && !visit[l][k]) cl = l;
					else if (map[l][k] == 'x' && visit[l][k] && cl != -1) {
						if (l - cl < min)min = l - cl;
						break;
					}
				}
		}
		for (int k = c - 1; k >= 0; k--)
			for (int l = r - 1; l >= 0; l--)
				if (map[l][k] == 'x' && !visit[l][k]) {
					map[l + min - 1][k] = 'x';
					map[l][k] = '.';
				}
		d *= -1;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
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