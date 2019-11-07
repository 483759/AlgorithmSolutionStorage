#include <cstdio>

int main() {
	char c;
	freopen("input.txt", "r", stdin);
	while (scanf("%c", &c) != EOF)
		printf("%c", c);

	return 0;
}