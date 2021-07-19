#include <cstdio>

int n, m, l, k, cake[1005];

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &l);

	int pre = 0;
	for (int i = 0, cur; i < m; i++) {
		scanf("%d", &cur);
		cake[i] = cur - pre;
		pre = cur;
	}
	cake[m] = l - pre;

	while (n--) {
		scanf("%d", &k);

		int left = 0, right = l + 1;
		int ans = right;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int cnt = 0, sum = 0,min=right;

			for (int i = 0; i <= m; i++)
				if (sum + cake[i] >= mid && (cnt<mid-1)) {
					if (sum+cake[i] < min)min = sum+cake[i];
					cnt++; sum = 0;
				}
				else sum += cake[i];
			if (sum >= mid) {
				cnt++;
				if (sum < min)min = sum;
			}
			
			if (cnt >= k)
				left = mid;
			else
				right = mid;			
		}
		printf("%d\n", left);
	}
	return 0;
}