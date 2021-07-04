#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, dp[2][1000005];
int k[2][1000005], t = 1;
vector<int> v;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	v.push_back(-1234567890);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[0][i]);

		if (v.back() < dp[0][i])
			v.push_back(dp[0][i]);
		else {
			auto it = lower_bound(v.begin(), v.end(), dp[0][i]);
			*it = dp[0][i];
		}
	}
	printf("%d", v.size() - 1);

	return 0;
}