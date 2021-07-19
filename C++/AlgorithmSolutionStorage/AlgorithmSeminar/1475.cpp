#include <cstdio>
int n, max, s, arr[10];
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%1d", &n) != EOF)	arr[n]++;
	s = arr[6] + arr[9]+1; arr[6] = arr[9] = s/2;
	for (int i = 0; i < 10; i++)
		if(arr[i])max = arr[i] > max ? arr[i] : max;
	printf("%d", max);
	return 0;
}