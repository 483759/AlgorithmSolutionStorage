//#include <iostream>
//#include <string>
//#define mod 1000000
//using namespace std;
//string str;
//int dp[5005] = { 1,1 };
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> str;
//	str.insert(0, "00");
//	for (int i = 2; i < str.length(); i++) {
//		if (i > 2) {
//			int num = (str[i - 1] - '0') * 10 + (str[i] - '0');
//			if (num >= 10 && num <= 26)
//				dp[i] = (dp[i] + dp[i - 2])%mod;
//		}
//		int num = str[i] - '0';
//		if (num >= 1 && num <= 9)
//			dp[i] = (dp[i] + dp[i - 1]) % mod;
//	}
//	printf("%d", dp[str.length() - 1]);
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//string s;
//int dp[5001],p=1;
//int func(int i) {
//	if (dp[i])return 0;
//	if (i >= s.length())return 0;
//	int a = (int)(s[i] - '0');
//
//	if (i + 1 >= s.length())return dp[i]=1;
//	int b = (int)(s[i + 1] - '0');
//	int k = a * 10 + b;
//
//	if (!b) {
//		if (a == 1 || a == 2)return dp[i] = 1 + func(i + 2);
//		p = 0;
//		return 0;
//	}
//	if (k > 26)return dp[i] = 1 + func(i + 1);
//	return dp[i]=1 + func(i + 1) + func(i + 2);	
//}
//int main() {
//	cin >> s;
//	func(0);
//	if (!p)printf("0");
//	else printf("%d", dp[0]);
//	return 0;
//}