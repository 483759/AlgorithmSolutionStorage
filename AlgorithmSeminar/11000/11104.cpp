#include <cstdio>
#define abs(x) x>0?x:-(x)
int n, v1,v2;
bool visit[3001], b;
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &v1); b = 1;
		for (int i = 1; i < n; i++) {
			scanf("%d", &v2);
			visit[abs(v1 - v2)] = true;
			v1 = v2;
		}
		for (int i = 1; i < n; i++) {
			if (!visit[i]) b = 0;
			visit[i] = 0;
		}
		if (b)printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
//#include <cstdio>
//int n, val[25], s;
//int func(int n, int d) {
//	if (n < 0)return 0;
//	return val[n] * d + func(n - 1, d * 2);
//}
//int main() {
//	scanf("%d", &n);
//	for (int a = 0; a < n; a++) {
//		for (int i = 0; i < 24; i++)scanf("%1d", &val[i]);
//		printf("%d\n", func(23, 1));
//	}
//	return 0;
//}