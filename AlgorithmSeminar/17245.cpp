#include <cstdio>
#include <vector>
#define ull unsigned long long
using namespace std;

int n;
int map[1001][1001];

int main() {
	freopen("input.txt", "r", stdin);
	ull left = 0, right = 0, sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		scanf("%d", &map[i][j]);
		sum += map[i][j];
		if (map[i][j] > right)right = map[i][j];
	}

	while (left + 1 < right) {
		ull mid = (left + right) / 2;
		ull cnt = 0;

		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
			cnt += mid > map[i][j] ? map[i][j]:mid;
		}
		if (((double)cnt/sum)>=0.5)
			right=mid;
		else left = mid;
	}
	printf("%lld", right);
	return 0;
}