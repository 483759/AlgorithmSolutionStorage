#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int arr[9], sum = 0, a, b;

	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sum -= 100;

	for (int i = 0; i < 9; i++)
		for (int j = i+1; j < 9; j++)
			if (arr[i] + arr[j] == sum) {
				a = arr[i];
				b = arr[j];
			}

	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
		if (arr[i] != a && arr[i] != b)
			printf("%d\n", arr[i]);
	return 0;
}