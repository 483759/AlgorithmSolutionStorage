#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001], sum[1000001], n1, n2, t, ans, test;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp[1] = 0; dp[2] = 1; sum[2] = 1;
	for (int i = 3, s; i <= 1000000; i+=2) {
		t = i; s = 0;
		dp[i + 1] = dp[(i+1) / 2] + 1;
		dp[i] = dp[i+1] + 1;
		sum[i] = sum[i - 1] + dp[i];
		sum[i + 1] = sum[i] + dp[i + 1];
	}
	cin >> test;
	for (int a = 1; a <= test; a++) {
		ans = 0;
		cin >> n1 >> n2;
		ans = sum[n2] - sum[n1] + dp[n1];
		cout << "Case #" << a << '\n' << ans << '\n';
	}
	return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int dp[1000005], n1, n2, t, ans;
//int func(int n) {
//	int& ref = dp[n];
//	if (ref != -1)return ref;
//	if (n % 2)return ref = func(n + 1) + 1;
//	else ref = func(n / 2) + 1;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	fill(dp, dp + 1000001, -1);
//	dp[1] = 0;
//	cin >> t;
//	for (int a = 1; a <= t; a++) {
//		ans = 0;
//		cin >> n1 >> n2;
//		for (int i = n1; i <= n2; i++) ans += dp[i] >= 0 ? dp[i] : func(i);
//		cout << "Case #" << a << '\n' << ans << '\n';
//	}
//	for (int i = 2; i <= n2; i++) {
//
//	}
//	return 0;
//}