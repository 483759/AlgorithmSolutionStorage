#include <cstdio>
int r, s, meteor[3001], ground[3001], min = 10000;
char map[3001][3001], c;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &r, &s);
	for (int i = 0; i < s; i++)meteor[i] = -100;
	for (int i = 0; i < r; i++) {
		scanf(" %c", &map[i][0]);
		for (int j = 1; j < s; j++)
			scanf("%c", &map[i][j]);
	}
	for (int j = 0; j < s; j++)
		for (int i = 0; i < r; i++) {
			if (map[i][j] == 'X')meteor[j] = i + 1;
			else if (map[i][j] == '#') {
				ground[j] = i + 1;
				break;
			}
		}
	for (int i = 0; i < s; i++)
		min = (min > ground[i] - meteor[i]) ? ground[i] - meteor[i] : min;
	min--;
	for (int i = r; i >= 0; i--)
		for (int j = 0; j < s; j++) {
			if (map[i][j] == 'X') {
				map[i][j] = '.';
				map[i + min][j] = 'x';
			}
		}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (map[i][j] == 'x')printf("X");
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}