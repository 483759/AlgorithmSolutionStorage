#include <iostream>
#include <math.h>
using namespace std;
int x, y, dp[100005], k, t, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int i = 0, b; i <= 100001; i++) {
		for (k = (int)sqrt(i * 2); k*(k + 1) > i * 2; k--);
		b = (i * 2 - k * (k + 1)) / 2;
		dp[i] = dp[b] + k;
	}
	for (int a = 1; a <= t; a++) {
		ans = 0;
		cin >> x >> y;
		for (int i = x; i <= y; i++)ans = dp[i] > ans ? dp[i] : ans;
		cout << "Case #" << a << '\n' << ans << '\n';
	}
	return 0;
}
#include <iostream>
#include <math.h>
#define ull unsigned long long
using namespace std;
int dp[2][100001], k, t, ans, d1, d2;
ull x, y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (ull i = 0, b; i <= 10000001; i++) {
		for (k = (int)sqrt(i * 2); k*(k + 1) > i * 2; k--);
		b = (i * 2 - k * (k + 1)) / 2;
		d1 = (int)log10(i) >= 1000000 ? 1 : 0;
		d2 = (int)log10(b) >= 1000000 ? 1 : 0;
		dp[d1][i % 1000000] = dp[d2][b % 1000000] + k;
	}
	for (int a = 1; a <= t; a++) {
		ans = 0;
		cin >> x >> y;
		for (int i = x, v = 0; i <= y; i++) {
			if (i >= 1000000)v = 1;
			ans = dp[v][i % 1000000] > ans ? dp[v][i % 1000000] : ans;
		}
		cout << "Case #" << a << '\n' << ans << '\n';
	}
	return 0;
}
//#include <iostream>
//#include <math.h>
//using namespace std;
//int x, y, dp[10001], k,t, ans;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> t;
//	for (int i = 0, b; i <= 10001; i++) {
//		for (k = (int)sqrt(i * 2); k*(k + 1) > i * 2; k--);
//		b = (i * 2 - k * (k + 1)) / 2;
//		dp[i] = dp[b] + k;
//	}
//	for (int a = 1; a <= t; a++) {
//		ans = 0;
//		cin >> x >> y;
//		for (int i = x; i <= y; i++)ans = dp[i] > ans ? dp[i] : ans;
//		cout << "Case #" << a << '\n' << ans << '\n';
//	}
//	return 0;
//}