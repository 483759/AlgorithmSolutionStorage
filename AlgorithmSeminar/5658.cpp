#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
int side, idx, n, k;
long long num[30];
vector<long long> ans;
long long func(char *s, int len) {
	long long ans = 0, t = 1;
	for (int i = len - 1, n; i >= 0; i--, t *= 16) {
		if (s[i] - '0' <= 9)n = s[i] - '0';
		else n = s[i] - 'A' + 10;
		ans += n * t;
	}
	return ans;
}
bool cmp(long long a, long long b) {
	return a > b;
}int main() {
	int t;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		char Str[29], str[36] = { '\0' };
		while (!ans.empty())
			ans.pop_back();
		scanf("%d %d", &n, &k);
		scanf("%s", Str);
		side = n / 4;	idx = 0;
		strncat(str, Str + n - side, side);
		strncat(str, Str, n);
		for (int j = 0; j < side; j++) {
			for (int i = 0; i < 4; i++) {
				char s[10];
				strncpy(s, str - j + (i + 1) * (side), side);
				s[side] = '\0';
				num[idx++] = func(s, side);
			}
		}
		sort(num, num + idx, cmp);
		ans.push_back(num[0]);
		for (int i = 1; i < n; i++)
			if (num[i] != num[i - 1])ans.push_back(num[i]);
		printf("%lld\n", ans[k - 1]);
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <math.h>
//#include <string.h>
//#include <vector>
//using namespace std;
//int side, idx, n, k;
//long long num[30];
//vector<long long> ans;
//long long func(char *s, int len) {
//	long long ans = 0, t = 1;
//	for (int i = len - 1, n; i >= 0; i--, t *= 16) {
//		if (s[i] - '0' <= 9)n = s[i] - '0';
//		else n = s[i] - 'A' + 10;
//		ans += n * t;
//	}
//	return ans;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	int t;
//	scanf("%d", &t);
//	for (int a = 0; a < t; a++) {
//		char Str[29], str[36] = { '\0' };
//		while (!ans.empty())
//			ans.pop_back();
//		scanf("%d %d", &n, &k);
//		scanf("%s", Str);
//		side = n / 4;	idx = 0;
//		strncat(str, Str + n - side, side);
//		strncat(str, Str, n);
//		for (int j = 0; j < side; j++) {
//			for (int i = 0; i < 4; i++) {
//				char s[10];
//				strncpy(s, str - j + (i + 1) * (side), side);
//				s[side] = '\0';
//				num[idx++] = func(s, side);
//				//printf("%s\n", s);
//				//printf("%lld\n\n", num[idx++]);
//			}
//		}
//		sort(num, num + idx);
//		ans.push_back(num[0]);
//		for (int i = 1; i < n; i++)
//			if (num[i] != num[i - 1])ans.push_back(num[i]);
//		//printf("%s\n", str);
//		//for (int i = 0; i < ans.size(); i++)printf("%lld\n", ans[i]);
//		printf("%lld\n", ans[n - k - 1]);
//	}
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//#include <math.h>
//#include <string.h>
//#include <vector>
//using namespace std;
//char Str[29], str[36];
//int side, idx, n, k;
//int num[20];
//vector<int> ans;
//int func(char *s, int len) {
//	int ans = 0, t = 1;
//	for (int i = len-1, n; i >=0; i--, t *= 16) {
//		if (s[i] - '0' <= 9)n = s[i] - '0';
//		else n = s[i] - 'A' + 10;
//		ans += n * t;
//	}
//	return ans;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d %d", &n, &k);
//	scanf("%s", Str);
//	side = n / 4;
//	strncat(str, Str + n - side, side);
//	strncat(str, Str, n);
//	for (int j = 0; j < side; j++) {
//		for (int i = 0; i < 4; i++) {
//			char s[10];
//			strncpy(s, str - j + (i + 1) * (side), side);
//			s[side] = '\0';
//			num[idx] = func(s, side);
//			printf("%s\n", s);
//			printf("%d\n\n", num[idx++]);
//		}
//	}
//	sort(num, num + idx);
//	ans.push_back(num[0]);
//	for (int i = 1; i < n; i++)
//		if (num[i] != num[i - 1])ans.push_back(num[i]);
//	printf("%s\n", str);
//	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
//	return 0;
//}