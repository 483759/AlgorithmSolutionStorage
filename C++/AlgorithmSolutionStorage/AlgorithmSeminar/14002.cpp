#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, dp[2][1000005];
vector<int> v;
int main() {
	scanf("%d", &n);
	v.push_back(-1234567890);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[0][i]);

		if (v.back() < dp[0][i]) {
			dp[1][i] = v.size();
			v.push_back(dp[0][i]);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), dp[0][i]);
			*it = dp[0][i];
			dp[1][i] = distance(v.begin(), it);
		}
	}
	printf("%d\n", (int)v.size() - 1);
	stack<int> s;
	for (int i = n; i > 0; i--)
		if (dp[1][i] == v.size() - 1) {
			s.push(dp[0][i]);
			v.pop_back();
		}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}

//#include <cstdio>
//int n,l, arr[1005],dp[2][1005];
//void func(int i) {
//	if (dp[1][i] == i) {
//		printf("%d ", arr[i]);
//		return;
//	}
//	func(dp[1][i]);
//	printf("%d ", arr[i]);
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//		dp[0][i] = 1; dp[1][i] = i;
//		for(int j=0;j<i;j++)
//			if (arr[j]<arr[i]
//				&& (dp[0][j] + 1)>dp[0][i]) {
//				dp[0][i] = dp[0][j] + 1;
//				dp[1][i] = j;
//			}
//		if (dp[0][i] > dp[0][l])l = i;
//	}
//	printf("%d\n", dp[0][l]);
//	func(l);
//	return 0;
//}