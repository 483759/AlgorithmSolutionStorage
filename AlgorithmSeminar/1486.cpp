#include <cstdio>
int n, b, arr[21], tc, ans = 987654321,dp[2][21];
bool v[21];
void func(int dep,int sum) {
	if (dep >= n) {
		if ((sum >= b)&& (sum - b < ans))ans = sum - b;
		return;
	}
	if(sum+arr[dep]-b<=ans)
	func(dep + 1,sum+arr[dep]);
	func(dep + 1,sum);
}
int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		ans = 987654321;
		scanf("%d%d", &n, &b);
		for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
		func(0,0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}