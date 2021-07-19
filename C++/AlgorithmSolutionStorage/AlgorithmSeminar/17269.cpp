#include<cstdio>
char a[101], b[101];
int n, m, s, i, k, d[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 }, c[201];
int main() {
	scanf("%d%d%s%s", &n, &m, a, b); n = n>m ? n : m;
	for (i = 0; i<n; i++) {
		if (a[i])c[k++] = d[a[i] - 'A'];
		if (b[i])c[k++] = d[b[i] - 'A'];
	}
	while (k>2) {
		for (i = 0; i<k - 1; i++) {
			c[i] = (c[i] + c[i + 1]) % 10;
		}
		k--;
	}
	printf("%d%%", c[0] * 10 + c[1]);
}
