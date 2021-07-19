#include <cstdio>

int main() {
	int arr[10], max, fmax;

	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	max = arr[0]; fmax = arr[1];
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			fmax = max;
			max = arr[i];
		}
	}
	printf("%d", max + fmax);
}