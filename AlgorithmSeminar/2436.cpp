#include <cstdio>
#define max(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
int a, b, c, s, m;
int main() {
	while (scanf("%d%d%d", &a, &b, &c)) {
		if (!a && !b && !c)return 0;
		m = max(a, b, c); s = 0;
		if (a != m)s += a * a;
		if (b != m)s += b * b;
		if (c != m)s += c * c;
		if (m*m == s)printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}
//#include <cstdio>
//#include <math.h>
//int a, b, c, d, t, m1, m2;
//int main() {
//	scanf("%d%d", &a, &b);
//	c = b / a;
//	d = sqrt(c);
//	for (int i = d; i >= 1; i--)
//		if (!(c%i)) {
//			m1 = i * a; m2 = (c / i)*a;
//			t = m2 % m1;
//			while (m2%m1) {
//				t = m1;
//				m1 = m2 % t;
//				m2 = t;
//			}
//			if (m1 == a) {
//				printf("%d %d", i*a, (c / i)*a);
//				return 0;
//			}
//		}
//	return 0;
//}