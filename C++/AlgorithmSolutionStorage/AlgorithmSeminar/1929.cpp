#include <cstdio>
#include <math.h>
bool chk[1000001] = { 1,1 };
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	for (int i = 2; i <= sqrt(b); i++) {
		if (!chk[i])
		for (int j = i * 2; j <= b; j += i)
			chk[j] = true;
	}
	for (int i = a; i <= b; i++)
		if (!chk[i])printf("%d\n", i);
	return 0;
}