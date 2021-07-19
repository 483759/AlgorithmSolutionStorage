#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;

int n, k, x, ans, S;
vector<int> score;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); S += x;
		score.push_back(x);
	}

	int left = 0, right = S;
	while (left <= right) {
		int mid = (left + right) / 2;
		int index = 0, sum = 0, min = INF, cnt = 0;
		for (int i = 0; i < n; i++) {
			sum += score[i];
			if (sum > mid) {
				if (sum < min)min = sum;
				sum = 0;
				cnt++;
			}
		}
		/*if (sum != 0 && (sum < mid)) {
			right = mid - 1;
			continue;
			min = sum;
			cnt++;
		}*/


		if ((cnt >= k)&&(min>=mid)) {
			left = mid + 1;
			if (min > ans)ans = min;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d", ans);
	return 0;
}