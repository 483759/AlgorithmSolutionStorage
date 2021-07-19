#include <vector>
#include <cstdio>
#define INF (1<<30)
using namespace std;

int d, n;
vector<int> oven;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d%d", &d, &n);
	oven = vector<int>(d + 1);
	int min = INF;
	for (int i = 0,o; i < d; i++) {
		scanf("%d", &o);
		if (o < min)min = o;
		oven[i] = o;
	}

	int right = d;
	while (n--) {
		int x;
		scanf("%d", &x);
		int left = -1;
		// left<right
		// oven[right] < x <= oven[left]
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (x <= oven[mid])
				left = mid;
			else right = mid;
		}
		right--;
		if (right < 0)break;
	}
	printf("%d", right<0?0:right+1);
	return 0;
}