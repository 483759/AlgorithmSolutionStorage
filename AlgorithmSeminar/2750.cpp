#include <cstdio>
#include <algorithm>
using namespace std;
int n, num[1001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &num[i]);
	sort(num, num + n);
	for (int i = 0; i < n; i++)printf("%d\n", num[i]);
	return 0;
}