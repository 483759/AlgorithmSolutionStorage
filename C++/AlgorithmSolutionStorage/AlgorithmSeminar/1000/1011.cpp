#include <cstdio>
#define abs(x) x<0?-(x):x
#define min(a,b) y-(a)<y-(b)?a:b
int t,x,y,k,c,min,ans;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &x, &y);
		k = 1; ans = 0; c = x+1;
		while (abs(y - c) != 1) {
			min = min(k, k - 1);
			min = min(min, k + 1);
			c += min;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}