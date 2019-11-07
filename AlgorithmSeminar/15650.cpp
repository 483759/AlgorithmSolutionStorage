#include <cstdio>
int n, m, v[9];
void func(int num,int d) {
	if (d > m) {
		for (int i : v)if(i)printf("%d ", i);
		printf("\n");
		return;
	}
	for (int i = num+1; i <= n; i++) {
		v[d] = i;
		func(i,d+1);
		v[d] = 0;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	func(0,1);
	return 0;
}