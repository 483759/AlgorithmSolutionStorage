#include <iostream>
using namespace std;
int t, n, dp[101] = {0, 1,1,1,2,2,3,4,5 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int i = 9; i <= 101; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n]<<'\n';
	}
	return 0;
}
//#include <iostream>
//using namespace std;
//int t, h, w, n, ans;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> t;
//	for (int l = 0; l < t; l++) {
//		cin >> h >> w >> n;
//		cout << n % h ? n % h : h;
//		cout << 1 + (int)((n - 1) / h) << '\n';
//	}
//	return 0;
//}