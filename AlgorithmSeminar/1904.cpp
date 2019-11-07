#include <iostream>
#include <string>
using namespace std;
int t;
string s;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		cout << s[0] << s[s.size() - 1]<<'\n';
	}
	return 0;
}
//#include <cstdio>
//#define mod 15746
//int n,n1=1,n2=2,ans;
//int main() {
//	scanf("%d", &n);
//	for (int i = 3; i <= n; i++) {
//		ans = ((n1%mod) + (n2%mod)) % mod;
//		n1 = n2; n2 = ans;
//	}
//	printf("%d", ans);
//	return 0;
//}