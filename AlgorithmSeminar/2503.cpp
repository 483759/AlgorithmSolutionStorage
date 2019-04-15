#include <cstdio>
bool arr[1000];
int n, num, s, b, on[3], nn[3];
bool func(int i, int arr[]) {
	int k = 2;
	while (i) {
		if (i % 10 == 0)
			return true;
		arr[k--] = num % 10;
		i /= 10;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int on[3];
		scanf("%d %d %d", &num, &s, &b);
		func(num, on);
		for (int i = 111; i <= 999; i++) {
			if (func(i, nn))continue;

			

		}
	}
}