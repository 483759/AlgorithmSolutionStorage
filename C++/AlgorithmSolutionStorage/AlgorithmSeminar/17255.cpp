#include <iostream>
#include <string>
using namespace std;
string num;
int func(int n) {
	int a = n % (int)(pow(10, (int)log10(n)));
	int b = n / 10;
	if (a == b)return 1;
	return func(a)+func(b);
}
int main() {
	cin >> num;
	return 0;
}
//#include <cstdio>
//#include <math.h>
//int num[9], t, l, arr[10], idx, number, ans, s, f;
//void func(int n, int d) {
//	if (n == number) ans++;
//	if (d >= l)return;
//	for (int i = 0, a, b; i < 10; i++) {
//		if (arr[i]) {
//			arr[i]--;
//			a = n * 10 + i; b = i * (int)pow(10, d) + n;
//			printf("%d %d %d\n", n, a, b);
//			func(a, d + 1);
//			if (a != b)	func(b, d + 1);
//			arr[i]++;
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	while (scanf("%1d", &t) != EOF) { arr[t]++; num[l++] = t; }
//	for (int i = 0; i < l; i++)number += num[l - i - 1] * pow(10, i);
//	func(0, 0);
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//#include <math.h>
//int num;
//int func(int n) {
//	int a = n % (int)(pow(10, (int)log10(n)));
//	int b = n / 10;
//	if (a == b)return 1;
//	return func(a)+func(b);
//}
//int main() {
//	printf("%d",func(1));
//	return 0;
//}