#include <cstdio>
#include <algorithm>
using namespace std;
int sum, n, a[51], b[51];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)sum += a[i] * b[n - 1 - i];
	printf("%d", sum);
	return 0;
}

/*
2 7 8 3 1
1 2 3 7 8
0 1 1 1 6
2 4 5 3 1

1 1 1 6 0
2 3 4 5 1

1 2 3 7 8

*/