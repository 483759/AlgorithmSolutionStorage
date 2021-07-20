#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<int> v(n);

	for (int i = 0, k; i < n; i++)
		scanf("%d", &v[i]);

	int left = 0, right = n - 1, ans=2000000000;
	pair<int, int> p;
	while (left + 1 <= right) {
		if (abs(v[left] + v[right]) <= ans) {
			ans = abs(v[left] + v[right]);
			p = make_pair(left, right);
		}
		int a = abs(v[left + 1] + v[right]);
		int b = abs(v[left] + v[right - 1]);

		if (a < b)left++;
		else right--;
	}
	printf("%d %d", v[p.first], v[p.second]);
	return 0;
}