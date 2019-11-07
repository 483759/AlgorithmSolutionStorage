#include <cstdio>
int N, arr[5], cnt;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		if (N == arr[i])
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}