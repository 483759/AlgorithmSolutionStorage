#include <cstdio>
int n, a[101], op[4], min = 100000000, max = -100000000;
void func(int num, int idx) {
	if (idx == n) {
		min = num < min ? num : min;
		max = num > max ? num : max;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!op[i])continue;
		op[i]--;
		switch (i) {
		case 0:
			func(num + a[idx], idx + 1);
			break;
		case 1:
			func(num - a[idx], idx + 1);
			break;
		case 2:
			func(num * a[idx], idx + 1);
			break;
		case 3:
			func(num / a[idx], idx + 1);
			break;
		}
		op[i]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++)scanf("%d", &op[i]);
	func(a[0], 1);
	printf("%d\n%d", max, min);
	return 0;
}