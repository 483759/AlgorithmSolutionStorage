#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int n,m,ans;

int main() {
	int left = 0,right=0;

	scanf("%d", &n);
	for (int i = 0,k; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
		if (k > right)right = k;
	}
	scanf("%d", &m);

	while (left <= right) {
		int mid = (left + right) / 2;

		unsigned long long sum = 0;
		for (unsigned long long k : v) {
			if (k > mid)sum += mid;
			else sum += k;
		}

		if (sum <= m) {
			left = mid + 1;
			if (mid > ans)ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d", ans);
	return 0;
}