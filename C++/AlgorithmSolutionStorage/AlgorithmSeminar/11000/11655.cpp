#include <cstdio>
char str[101];
int i, n;
int main() {
	scanf("%[^\n]s", str);
	while (str[i] != NULL) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = (str[i]-65 + 13) % 26 + 65;
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] = (str[i] - 97+13) % 26 + 97;
		i++;
	}
	printf("%s", str);
	return 0;
}