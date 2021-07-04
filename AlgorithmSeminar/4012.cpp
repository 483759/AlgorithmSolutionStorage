#include <cstdio>
int n,s[17][17],ans,tc,index[17];
void func(int dep) {
	if (dep == n) {
		int a = 0, b = 0,sub;
		for (int i = 0; i < n; i++) {	//식재료 A 시너지 확인
			int cur = index[i];
			for (int j = 0; j < n; j++) {
				if (cur != index[j]||i==j)continue;

				if (cur)a += s[i][j];
				else b += s[i][j];
			}
		}

		if (a > b)sub = a - b;
		else sub=b - a;

		if (sub < ans)ans = sub;

		return;
	}

	func(dep + 1);
	index[dep] = 1;
	func(dep + 1);
	index[dep] = 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n); ans = 987654321;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &s[i][j]);

		func(0);

		printf("#%d %d\n", T, ans);
	}
	return 0;
}