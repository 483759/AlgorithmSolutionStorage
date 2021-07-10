#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vector<int> a, b;

		for (int i = 0, k; i < n; i++) {
			scanf("%d", &k); a.push_back(k);
		}
		for (int i = 0, k; i < m; i++) {
			scanf("%d", &k); b.push_back(k);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ans = 0, point = 0;
		for (int i = 0; i < n; i++) {
			while ((point < m) && (a[i] > b[point]))
				point++;
			ans += point;
		}
		printf("%d\n", ans);
	}
	return 0;
}