#include <cstdio>
#include <math.h>
int n,r,c,ans;
void func(int k,int rs,int rf,int cs, int cf) {
	if ((r < rf/2)&&(c < cf/2)) {
		func(k,rs,rf/2,cs,cf/2);
	}
	else if ((r < rf/2) && (c >= cf/2)) {
		func(rs,rf/2,cf/2,cf);
	}
	else if ((r >= rf/2) && (c < cf/2)) {
		func(rf/2,rf,cs,cf/2);
	}
	else {
		func(rf/2,rf,cf/2,cf);
	}
}
int main() {
	scanf("%d%d%d", &n, &r, &c);
	func(0, pow(2, n), 0, pow(2, n));
	return 0;
}
r,c     r,c+1
r+1,c   r+1,c+1

r,c     r,c+2
r+2,c   r+2,c+2