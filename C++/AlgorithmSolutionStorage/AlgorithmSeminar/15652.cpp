#include <cstdio>
#include <math.h>
int a, b;
double m, p;
int main() {
	scanf("%d%d", &a, &b);
	m = (b - a) / (double)400;
	p = 1 / (1 + pow(10, m));
	printf("%.10lf", p);
	return 0;
}
//arr[2] = 1; 2 1
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n, m, v[9];
//void func(int num,int d) {
//	if (d > m) {
//		for (int i : v)if(i)printf("%d ", i);
//		printf("\n");
//		return;
//	}
//	for (int i = num; i <= n; i++) {
//		v[d] = i;
//		func(i,d + 1);
//		v[d] = 0;
//	}
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	func(1,1);
//	return 0;
//}