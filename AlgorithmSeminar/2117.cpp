#include <cstdio>
#include <math.h>
int tc, n, m, map[21][21];
int cost(int k) { return 2 * k * k - 2 * k + 1; }
bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
int main() {
	freopen("input.txt", "r", stdin);
	//for (int i = 1; i <= 10; i++)printf("%d\n", cost(i));
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		int ans = 1, h = 0, k = 2;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j])h++;
			}

		while (h * m >= cost(k)) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					int sum = 0;
					for (int a = i - k; a <= i + k; a++)
						for (int b = j - k; b <= j + k; b++) {
							if (!safe(b, a))continue;
							if (abs(a - i) + abs(b - j) < k
								&& map[a][b])
								sum++;
						}
					if (sum * m >= cost(k)
						&& sum > ans)
						ans = sum;
				}
			k++;
		}
		printf("#%d %d\n", T, ans);
	}
	return 0;
}