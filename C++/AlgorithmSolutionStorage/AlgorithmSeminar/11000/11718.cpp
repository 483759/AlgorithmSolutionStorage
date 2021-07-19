#include <cstdio>
int main() {
	freopen("input.txt", "r", stdin);
	char arr[100];
	while (scanf(" %[^\n]s", arr) != EOF)
		printf("%s\n", arr);
	return 0;
}