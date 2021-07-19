#include <cstdio>
int tc,n,op[4],num[13],max,min;
void func(int k,int dep) {
	if (dep == n) {
		if (k > max)max = k;
		if (k < min)min = k;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!op[i])continue;

		op[i]--;
		switch (i) {
		case 0:
			func(k + num[dep], dep + 1);
			break;
		case 1:
			func(k - num[dep], dep + 1);
			break;
		case 2:
			func(k * num[dep], dep + 1);
			break;
		case 3:
			func(k / num[dep], dep + 1);
			break;
		}
		op[i]++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		max = -100000000, min = max * -1;
		scanf("%d", &n);
		for (int i = 0; i < 4; i++)
			scanf("%d", &op[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		func(num[0], 1);

		printf("#%d %d\n", T, max - min);
	}
	return 0;
}