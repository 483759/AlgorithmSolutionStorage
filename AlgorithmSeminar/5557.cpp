#include <cstdio>
int dp[41][41],n,m,s[41];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < m; i++)scanf("%d", &s[i]);
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//int dp[4001][4001], m;
//string a, b;
//int main() {
//	cin >> a >> b;
//	for (int i = 1; i <= a.length(); i++)
//		for (int j = 1; j <= b.length(); j++) {
//			if (a[i-1] == b[j-1]) {
//				if (!i || !j)continue;
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//				if (dp[i][j] > m)
//					m = dp[i][j];
//			}
//		}
//	cout << m;
//}
//#include <cstdio>
//int n,result,val[100],ans;
//void func(int num, int i) {
//	if ((num < 0 || num>20)&&i != n)return;
//	if (i == n-1) { if(num==result)ans++; return; }
//	func(num + val[i], i + 1);
//	func(num - val[i], i + 1);
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++)scanf("%d", &val[i]);
//	scanf("%d", &result);
//	func(val[0], 1);
//	printf("%d", ans);
//	return 0;
//}