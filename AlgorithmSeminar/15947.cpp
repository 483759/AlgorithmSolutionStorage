#include <cstdio>
int N, k;
void print(int line, int num) {
	int i;
	printf("tu");
	i = line + 2 - num;
	if (i < 5)
		for (int j = 0; j < i; j++)
			printf("ru");
	else
		printf("+ru*%d", i);
		
}
int main() {
	scanf("%d", &N);
	switch (N % 14) {
	case 1:
	case 13:
		printf("baby");
		break;
	case 2:
	case 0:
		printf("sukhwan");
		break;
	case 3:
	case 7:
	case 11:
		print((int)(N / 14), 0);
		break;
	case 4:
	case 8:
	case 12:
		print((int)N / 14, 1);
		break;
	case 5:
		printf("very");
		break;
	case 6:
		printf("cute");
		break;
	case 9:
		printf("in");
		break;
	case 10:
		printf("bed");
		break;
	}
	return 0;
}