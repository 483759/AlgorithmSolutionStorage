#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000001], N;
int func(int X) {
	if (X == 1)return 0;
	int& ref = arr[X];
	if (ref)return ref + 1;
	ref = func(X - 1);
	if (X % 3 == 0)ref = min(func(X / 3), ref);
	if (X % 2 == 0)ref = min(func(X / 2), ref);
	return ref + 1;
}
int main() {
	scanf("%d", &N);
	printf("%d", func(N));
	return 0;
}