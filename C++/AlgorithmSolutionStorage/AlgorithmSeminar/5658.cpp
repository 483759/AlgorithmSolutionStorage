#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define INF 987654321
using namespace std;
int n,k,w,T;
vector<int> v;
string pass;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		cin >> pass;
		w = n / 4;
		for (int i = 0; i < w; i++) {	//회전
			for (size_t j = 0; j < 4; j++)	//4면에 대해
			{
				int sum = 0;
				int p = pow(16, w - 1);
				for (size_t l = 0; l < w; l++)
				{
					int idx = (i + j * w + l) % n;
					int num;
					if (pass[idx] >= 'A' && pass[idx] <= 'F')
						num = 10 + pass[idx] - 'A';
					else num = pass[idx] - '0';

					sum += p * num;
					p /= 16;
				}
				v.push_back(sum);	
			}
		}
		int idx = 1;
		v.push_back(INF);
		sort(v.begin(), v.end(),greater<>());
		for (int i = 1; i <v.size(); i++) {
			if (idx == k) {
				printf("#%d %d\n", tc,v[i]);
				break;
			}
			if (v[i] != v[i - 1])idx++;
		}
	}
	return 0;
}

//#include <cstdio>
//#include <math.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int tc, n, k;
//long long ans;
//char str[30], c;
//vector<long long> v;
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int t = 1; t <= tc; t++) {
//		scanf("%d%d", &n, &k);
//		scanf(" %s", str);
//		int m = n / 4;
//
//		for (int rot = 0; rot < m; rot++) {//회전
//			for (int i = 0; i < 4; i++) {//각 면 계산
//				long long sum = 0, check = 1;
//				for (int j = 0; j < m; j++) {
//					long long S = 0;
//					c = str[(rot + i * m + j) % n];
//					if (c >= '0' && c <= '9')
//						S = (int)(c - '0');
//					else
//						S += (int)(c - 'A' + 10);
//					for (int h = 0; h < m - j - 1; h++)
//						S *= 16;
//					sum += S;
//				}
//				for (auto f : v) {
//					if (sum == f)check = 0;
//				}
//				if (check)v.push_back(sum);
//			}
//		}
//		sort(v.begin(), v.end());
//		ans = v[v.size() - k];
//		v.clear();
//
//		printf("#%d %lld\n", t, ans);
//	}
//	return 0;
//}
//
//
//
//
//











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
//bool cmp(long long a, long long b) {
//	return a > b;
//}int main() {
//	int t;
//	freopen("input.txt", "r", stdin);
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
//			}
//		}
//		sort(num, num + idx, cmp);
//		ans.push_back(num[0]);
//		for (int i = 1; i < n; i++)
//			if (num[i] != num[i - 1])ans.push_back(num[i]);
//		printf("%lld\n", ans[k - 1]);
//	}
//	return 0;
//}
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