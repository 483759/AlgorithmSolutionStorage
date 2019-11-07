#include <cstdio>

int arr[10];
int main() {
	int N, K, num = 0;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[N - i - 1]);

	for (int i = 0; i < N; i++) {
		num += K / arr[i];
		K %= arr[i];
	}

	printf("%d", num);
	return 0;
}