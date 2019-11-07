#include <cstdio>
#include <algorithm>
using namespace std;
int n, dp[1001], p[10001];
int money(int n) {
	if (!n)return 0;
	int& ref = dp[n];
	if (ref) return ref;
	if (n == 1)return ref = p[1];
	for (int i = 1; i <= n; i++) {
		int temp = money(n - i)+p[i];
		ref = temp > ref ? temp : ref;
	}
	return ref;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);
	printf("%d", money(n));
	return 0;
}