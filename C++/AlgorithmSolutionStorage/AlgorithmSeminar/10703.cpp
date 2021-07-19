#include <cstdio>
int r, s,dist;
char map[3005][3005];
int main() {
	scanf("%d%d", &r, &s);
	scanf(" ");
	for (int i = 0; i < r; i++)
		scanf("%s", &map[i]);
	for (int j = 0; j < s; j++)
		map[r][j] = '#';

	dist = r;
	for(int j=0;j<s;j++) {
		int t = r, d = 0;

		for (int i = r; i >= 0; i--) {
			if (map[i][j] == '#')d = 0;
			else if (map[i][j] == '.')d++;
			else if (d < t)t = d;
		}
		if (t < dist)
			dist = t;
	}


	for (int j = 0; j < s; j++)
		for (int i = r; i >= 0; i--)
			if(map[i][j]=='X'){
				map[i + dist][j] = 'X';
				map[i][j] = '.';
		}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}

	return 0;
}