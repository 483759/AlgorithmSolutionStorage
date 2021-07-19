#include <cstdio>
int arr[1000000];
int main() {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0, t; i < n; i++) {
		scanf("%d", &t);
		arr[t]++;
	}

	for (int i = 0; i < 1000000; i++)
		if (arr[i] != 0)
			for(int j=0;j<arr[i];j++)
			printf("%d\n", i);
	return 0;
}