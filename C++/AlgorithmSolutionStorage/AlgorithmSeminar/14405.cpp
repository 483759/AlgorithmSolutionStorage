#include <cstdio>
int state;
char str[5001];
int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != NULL;)
		switch (state) {
		case 0:
			if (str[i] == 'p')
				state = 1;
			else if (str[i] == 'k')
				state = 2;
			else if (str[i] == 'c')
				state = 3;
			else
				state = 4;
			break;
		case 1:
			if (str[i + 1] == 'i') {
				state = 0;
				i+=2;
			}
			else state = 4;
			break;
		case 2:
			if (str[i + 1] == 'a') {
				state = 0;
				i+=2;
			}
			else state = 4;
			break;
		case 3:
			if (str[i + 1] == 'h'&&str[i + 2] == 'u') {
				state = 0;
				i += 3;
			}
			else state = 4;
			break;
		default:
			printf("NO");
			return 0;
			break;
		}
	printf("YES");
	return 0;
}