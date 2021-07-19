#include <cstdio>
int chk[26];
char c, idx;
int main() {
	for (int i = 0; i < 26; i++)
		chk[i] = -1;
	while (scanf("%c", &c) != EOF) {
		if (chk[c - 'a'] == -1)
			chk[c - 'a'] = idx;
		idx++;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", chk[i]);
}
//#include <cstdio>
//int a, b,x,y, gcd, lcm;
//int main() {
//	scanf("%d%d", &a, &b);
//	x = a; y = b;
//	do {
//		gcd = x % y;
//		x = y; y = gcd;
//	} while (y != 0);
//	gcd = x; lcm = a * b / gcd;
//	printf("%d\n%d", gcd, lcm);
//	return 0;
//}