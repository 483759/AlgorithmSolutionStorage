#include <cstdio>
int t;
int main() {
	scanf("%d", &t);
	for (int i = 0, a, b; i < t; i++) {
		scanf("%d%d",&a,&b);
		printf("%d\n", a + b);
	}
	return 0;
}

//#include <cstdio>
//int ans;
//int func(char c) {
//	if (c <= 'O')return (c - 'A') / 3 + 2;
//	if (c <= 'S')return 7;
//	if (c <= 'V')return 8;
//	return 9;
//}
//int main() {
//	char c[16];
//	scanf("%s", &c);
//	for (int i = 0; c[i] != NULL; i++) {
//		ans += func(c[i]) + 1;
//	}
//	printf("%d", ans);
//	return 0;
//}