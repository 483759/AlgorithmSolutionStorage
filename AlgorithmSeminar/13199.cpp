#include <cstdio>
int t, p, m, f, c;
int main() {
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		int c1, c2, t1;
		scanf("%d%d%d%d", &p, &m, &f, &c);
		c1 = c2 = m / p;
		t1 = m / p * c;
		do {
			c1 += t1 / f;
			t1 = (int)(t1 / f)*c + t1 % f;
		} while (t1 >= f);
		c2 += m / p * c / f;
		printf("%d\n", c1 - c2);
	}
	return 0;
}


//(250000 / 10000) * 2 = 25 / 50
//50 / 5 * 2 = 35 / 20
//20 / 5 * 2 = 39 / 8
//8 / 5 * 2 = 40 / 4
//(8 / 5 + 8 % 5) / 5 * 2 = 41 / 2
//(50 / 5 + 50 % 5 ) / 5 * 2 = 
//
//(250000 / 10000) * 2 = 25 / 50
//50 / 5 = 35