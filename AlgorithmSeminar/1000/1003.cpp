#include <cstdio>
int t, n;
struct s { int z, o; };
s dp[41] = { { 1,0 },{ 0,1 } }, p;
s fibonacci(int n) {
	if (n <= 1)return dp[n];
	else {
		if (dp[n].z || dp[n].o)return dp[n];
		s f1 = fibonacci(n - 1), f2 = fibonacci(n - 2);
		dp[n].z = f1.z + f2.z; dp[n].o = f1.o + f2.o;
		return dp[n];
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		p = fibonacci(n);
		printf("%d %d\n", p.z, p.o);
	}
	return 0;
}