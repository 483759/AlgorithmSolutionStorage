#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[15005],ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	sort(&a[0], &a[n]);
	int s = 0, e = n-1;
	while (s<e) {
		if (a[s] + a[e] == m) {
			ans++;
			s++; e--;
		}
		else if (a[s] + a[e] < m)
			s++;
		else e--;
	}
	printf("%d", ans);
	return 0;
}