#include <cstdio>
int n, ans;
int main() {
	scanf("%d", &n);
	return 0;
}
//#include <cstdio>
//int n,result,val[100],ans;
//void func(int num, int i) {
//	if ((num < 0 || num>20)&&i != n)return;
//	if (i == n-1) { if(num==result)ans++; return; }
//	func(num + val[i], i + 1);
//	func(num - val[i], i + 1);
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++)scanf("%d", &val[i]);
//	scanf("%d", &result);
//	func(val[0], 1);
//	printf("%d", ans);
//	return 0;
//}