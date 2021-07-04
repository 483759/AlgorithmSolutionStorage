#include <cstdio>
int t = 10, n;
char c[9][9];
int main() {
	freopen("input.txt", "r", stdin);
	while (t--) {
		int ans = 0;
		scanf("%d", &n);
		scanf(" ");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				scanf("%c", &c[i][j]);
			scanf(" ");
		}

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				bool row = true, col = true;
				char str[2][4];
				for (int k = 0; k < n; k++) {
					if (k < n / 2) {
						str[0][k] = c[i][j + k];
						str[1][k] = c[i + k][j];
					}
					else if ((n % 2) && k == n / 2) {
						continue;
					}
					else {
						if (str[0][n - k - 1] != c[i][j + k])
							col = 0;
						if (str[1][n - k - 1] != c[i + k][j])
							row = 0;
					}
				}
				if (row)ans++;
				if (col)ans++;
			}
		printf("#%d %d\n", 10 - t, ans);
	}
	return 0;
}