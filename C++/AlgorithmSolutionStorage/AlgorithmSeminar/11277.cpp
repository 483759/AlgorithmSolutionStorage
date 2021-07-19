#include <cstdio>
#include <math.h>
int n, m,val[22],cla[101][2];
bool ans;
bool sat(int dep) {
	if (dep == m)return 1;
	return ((cla[dep][0] > 0) || (cla[dep][1] > 0))&&sat(dep+1);
}
void func(int dep) {
	if (ans)return;
	if (dep > n)
	{
		bool s = 1;
		for (int i = 0; i < m; i++) {
			s &= (cla[i][0] > 0?val[cla[i][0]]: !val[abs(cla[i][0])]) || (cla[i][1] > 0 ? val[cla[i][1]] : !val[abs(cla[i][1])]);
		}
		if (s) {
			printf("1\n");
			for (int i = 1; i <= n; i++)
				printf("%d ", val[i]);
			ans = 1;
		}
		return;
	}
	func(dep + 1);
	val[dep] = 1;
	func(dep + 1);
	val[dep] = 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &cla[i][0], &cla[i][1]);
	func(1);
	if(!ans)printf("0");
	return 0;
}