#include <cstdio>
int n, num[11], ans=-2147483640;
char c, op[11];
bool b[10];
void func(int dep) {
	if (dep == n / 2) {
		int sum = num[0], tmp;
		for (int i = 0; i < n / 2; i++)
			if (b[i + 1]) {
				if (op[i + 1] == '+')tmp = num[i + 1] + num[i + 2];
				else if (op[i + 1] == '-')tmp = num[i + 1] - num[i + 2];
				else tmp = num[i + 1] * num[i + 2];

				if (op[i] == '+')sum += tmp;
				else if (op[i] == '-') sum -= tmp;
				else sum *= tmp;
				i++;
			}
			else {
				if (op[i] == '+')sum += num[i + 1];
				else if (op[i] == '-')sum -= num[i + 1];
				else sum *= num[i + 1];
			}
			ans = sum > ans ? sum : ans;
			return;
	}
	if (!b[dep - 1]) {
		b[dep] = true;
		func(dep + 1);
	}
	b[dep] = false;
	func(dep + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i % 2) scanf("%c", &op[i / 2]);
		else scanf("%d", &num[i / 2]);
	}
	if (n > 1)
		func(1);
	else return printf("%d", num[0]);
	printf("%d", ans);
	return 0;
}