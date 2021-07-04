#include <cstdio>
int t=10,n,arr[101][101],sum[3][100];
int main() {
	freopen("input.txt", "r", stdin);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < 3; i++)for (int j = 0; j < 100; j++)sum[i][j] = 0;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &arr[i][j]);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				sum[0][i] += arr[i][j];
				sum[1][i] += arr[j][i];
			}
			if (ans < sum[0][i])ans = sum[0][i];
			if (ans < sum[1][i])ans = sum[1][i];
		}
		for (int i = 0; i < 100; i++) {
			sum[2][0] += arr[i][i];
			sum[2][1] += arr[i][99 - i];
		}
		if (ans < sum[2][0])ans = sum[2][0];
		if (ans < sum[2][1])ans = sum[2][1];
		printf("#%d %d\n", n, ans);			   
	}
	return 0;
}