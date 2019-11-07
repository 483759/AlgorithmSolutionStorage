//#include <cstdio>
//#include <math.h>
//int t, x1, yo, r1, x2, y2, r2, mr;
//int main() {
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++) {
//		scanf("%d%d%d%d%d%d", &x1, &yo, &r1, &x2, &y2, &r2);
//		int d = pow(x1 - x2, 2) + pow(yo - y2, 2);
//		int rd = pow(r1 - r2, 2);
//		int rs = pow(r1 + r2, 2);
//		if (x1 == x2 && yo == y2 && r1 == r2)printf("-1\n");
//		else if (d > rs || d<rd)	printf("0\n");
//		else if (d == rd || d == rs)printf("1\n");
//		else if (d > rd && d < rs)printf("2\n");
//	}
//	return 0;
//}