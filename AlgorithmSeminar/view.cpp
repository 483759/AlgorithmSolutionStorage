#include <cstdio>
int t,n, h, b[1001], ans;
int main() {
	freopen("input.txt", "r", stdin);
	for (int j = 1; j <= 10;j++) {
		scanf("%d", &n); ans = 0;
		for (int i = 0; i < n; i++)scanf("%d", &b[i]);
		for (int i = 2; i < n - 2; i++) {
			int s = 0;
			if (b[i - 2] >= b[i] || b[i - 1] >= b[i] 
				|| b[i + 1] >= b[i] || b[i + 2] >= b[i])continue;
			s = b[i - 2];
			if (b[i - 1] > s)s = b[i - 1];
			if (b[i + 1] > s)s = b[i + 1];
			if (b[i + 2] > s)s = b[i + 2];
			ans += b[i] - s;
		}
		printf("#%d %d\n", j,ans);
	}
	return 0;
}