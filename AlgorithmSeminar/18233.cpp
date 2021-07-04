#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, p, e, arr[2][21];

int main() {
	scanf("%d%d%d", &n, &p, &e);
	if (p > n) {
		printf("-1"); return 0;
	}
	vector<bool> v(n, 0);
	for (int i = 0; i < n; i++)scanf("%d%d", &arr[0][i], &arr[1][i]);
	for (int i = n - p; i < n; i++)v[i] = 1;
	do {
		int sum[2] = { 0 };
		for (int i = 0; i < n; i++) {
			if (!v[i])continue;
			sum[0] += arr[0][i];
			sum[1] += arr[1][i];
		}
		if (e >= sum[0] && e <= sum[1]) {
			int ans[21] = { 0 };
			for (int i = 0; i < n; i++)
				if (v[i]) {
					ans[i] = arr[0][i];
					e -= arr[0][i];
				}
			for (int i = 0; i < n; i++)
				if (v[i] && ans[i] < arr[1][i] && e) {
					if (e >= arr[1][i] - arr[0][i]) {
						ans[i] += e - (arr[1][i] - arr[0][i]);
						e -= (arr[1][i] - arr[0][i]);
					}
					else {
						ans[i] += e;
						break;
					}
				}
			for (int i = 0; i < n; i++)
				printf("%d ", ans[i]);
			return 0;
		}
	} while (next_permutation(v.begin(), v.end()));
	printf("-1");
	return 0;
}