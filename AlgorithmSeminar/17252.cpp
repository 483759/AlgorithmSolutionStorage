#include <cstdio>
#include <math.h>
int i=1,k;
long long n[41],t=1,x;
long long sum(int n) {
	long long j,s=0;
	for(j=1,k=0;k<n;k++,j*=3)s+=j;
	return s;
}
bool func(int dep, long long num) {
	bool b = false;
	if (!dep)return num==x;
	b= func(dep - 1, num + n[dep]);
	if((dep != i - 1) && sum(dep)>=x)b|=func(dep - 1, num);
	return b;
}
int main() {
	scanf("%lld", &x);
	for (; i<41&&t<=x; i++,t*=3)n[i] = t;
	printf("%s", func(i-1, 0)&&x ? "YES" : "NO");
	return 0;
}
////2147483647
//1 3 9 27 81 243 729
//80