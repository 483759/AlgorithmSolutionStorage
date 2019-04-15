#include <cstdio>
char str[101];
int i, cnt, n;
int main() {
	scanf("%s", str);
	while (str[i] != NULL) {
		printf("%c", str[i++]);
		if (i % 10 == 0)
			printf("\n");
	}
	return 0;
}