#include <cstdio>
int n,ans[10001],cnt,idx;
int main() {
	scanf("%d", &n);
	for (int i = 666,j; i < 3000000; i++) {
		j = i; cnt = 0;
		while (j) {
			if (j % 1000 == 666)cnt = 1;
			j /= 10;
		}
		if (cnt) idx++;
		if (idx == n) { printf("%d", i); return 0; }
	}
	return 0;
}
/*
0666
1666
2666
...
5666
6660
6661
6662
...
6666
...
6669
7666
8666
9666
10666

*/