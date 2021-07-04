#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> d;
int T;
int main() {
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
	}
	return 0;
}
//#include <cstdio>
//#include <math.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, ab[21][21], ans = 987654321;
//int func(vector<int> v) {
//	int sum = 0;
//	for (int a : v)
//		for (int b : v) {
//			sum += ab[a][b];
//		}
//	return sum;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%d", &ab[i][j]);
//
//	vector<bool> team(n, 0);
//	for (int j = n - 1; j >= n/2; j--)team[j] = true;
//	do {
//		if (ans == 0)break;
//		vector<int> a, b;
//		for (int j = 0; j < team.size(); j++) {
//			if (team[j])a.push_back(j);
//			else b.push_back(j);
//		}
//		int u = func(a);
//		int v = func(b);
//		ans = min(ans, abs(u - v));
//	} while (next_permutation(team.begin(), team.end()));
//	printf("%d", ans);
//	return 0;
//}

//#include <cstdio>
//int n, s[21][21], ans=10000000;
//bool b[21];
//void func(int dep, int last) {
//	if (dep == n / 2) {
//		int start = 0, link = 0, sub;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++) {
//				if (b[i] && b[j])start += s[i][j];
//				else if(!b[i]&&!b[j]) link += s[i][j];
//			}
//		sub = start > link ? start - link : link - start;
//		if (sub < ans)ans = sub;
//		return;
//	}
//	for (int i = last + 1; i < n / 2 + 1 + dep; i++) {
//		b[i] = true;
//		func(dep + 1, i);
//		b[i] = false;
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%d", &s[i][j]);
//	func(0, -1);
//	printf("%d", ans);
//	return 0;
//}