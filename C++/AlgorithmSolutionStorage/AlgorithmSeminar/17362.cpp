#include <cstdio>
int n, ans, a[] = { 4,3,2,1,2,3,4,5 };
int main() {
	scanf("%d", &n);
	if(n<6)printf("%d",n);
	else printf("%d", (a[(n-6)%8]));
	return 0;
}