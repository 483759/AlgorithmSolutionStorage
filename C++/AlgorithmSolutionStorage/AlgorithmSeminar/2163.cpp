#include <cstdio>
int n;
int main() {
	scanf("%d", &n);
	printf("%d", (!(n % 4) && (n % 100)) || !(n % 400));
	return 0;
}
//#include <cstdio>
//#define min
//int n, m;
//int func(int cn, int cm) {
//	if (cn == cm == 1)return 1;
//	int ref = func(cn, cm / 2) + func(cn, cm - cm / 2);
//	ref = min(ref, func(cn / 2, cm) + func(cn - cn / 2, cm));
//	dp[cm][cn] = ref;
//	return ref;
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	fill(&dp[1][1], &dp[n][m + 1], -1);
//	dp[1][1] = 0;
//	printf("%d", func(n, m));
//	return 0;
//}