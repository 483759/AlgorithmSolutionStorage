#include <cstdio>
#include <algorithm>
int n, a[1001],dp[1001],ans,t1,t2;
int main() {
	freopen("input.txt","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int k = 0; k < n; k++) {
		int n1=0, n2=0;
		for (int i = 0; i <= k; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++)
				if (a[j]<a[i] && dp[j] + 1>dp[i])
					dp[i] = dp[j] + 1;
		}
		for (int i = k; i < n; i++) {
			dp[i] = 1;
			for (int j = k; j < i; j++)
				if (a[j]>a[i] && dp[j] + 1>dp[i])
					dp[i] = dp[j] + 1;
		}
		for (int i = 0; i < k; i++)n1 = dp[i] > n1 ? dp[i] : n1;
		for (int i = k; i < n; i++)n2 = dp[i] > n2 ? dp[i] : n2;
		if (a[k - 1] == a[k])n2--;
		ans = n1 + n2 > ans ? n1 + n2 : ans;
	}
	printf("%d", ans);
	return 0;
}