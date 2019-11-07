#include <cstdio>
int n,m,a[101],ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for (int k = j + 1,t; k < n; k++) {
				t = a[i] + a[j] + a[k];
				if (t > ans&&t <= m)ans = t;
			}
	printf("%d", ans);
	return 0;
}