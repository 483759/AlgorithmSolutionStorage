#include <cstdio>
#include <math.h>
int n,T,map[51][51];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)scanf("%1d", &map[i][j]);
			scanf(" ");
		}

		int ans = 0,h=n/2;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (abs(i - h) + abs(j - h) <= h)
					ans+=map[i][j];

		printf("#%d %d\n", tc, ans);
	}
	return 0;
}