#include <cstdio>
int a, b;
int main() {
	while (scanf("%d%d", &a, &b)) {
		if (!a && !b)return 0;
		printf("%d\n", a + b);
	}
}
//#include <cstdio>
//int n, w[17][17];
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
//		scanf("%d", &w[i][j]);
//	return 0;
//}