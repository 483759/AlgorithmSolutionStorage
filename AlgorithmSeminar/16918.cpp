#include <cstdio>
#include <vector>
using namespace std;
int r, c, n, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
char chr,map[201][201];
bool boom[201][201];
struct p { int x, y; };
vector<p> v;
bool safe(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}
int main() {
	scanf("%d%d%d", &r, &c, &n);
	for (int i = 0; i < r; i++) {
		scanf(" %c", &map[0][i]);
		if (map[0][i] == 'O')v.push_back({i, 0});
		for (int j = 1; j < c; j++) {
			scanf("%c", &map[j][i]);
			if (map[j][i] == 'O')v.push_back({i, j});
		}
	}
	if (n % 4 == 1)
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)printf("%c", map[j][i]);
			printf("\n");
		}
	else if (n % 2 == 0)
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				printf("O");
			printf("\n");
		}
	else if (n % 4 == 3) {
		for (int j = 0; j < v.size();j++) {
			p pt = v[j];
			boom[pt.y][pt.x] = true;
			for (int i = 0; i < 4; i++)
				if (safe(pt.x + dx[i], pt.y + dy[i]))boom[pt.y + dy[i]][pt.x + dx[i]] = true;
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!boom[j][i])printf("O");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}