#include <cstdio>
int s, n, arr[11];
int lcd[5][11] = {
	{1,0,1,1,0,1,1,1,1,1,1},
{4,2,2,2,4,3,3,2,4,4,4},
{0,0,1,1,1,1,1,0,1,1,0},
{4,2,3,2,2,2,4,2,4,2,4},
{1,0,1,1,0,1,1,0,1,1,1}
};
void func(int k) {
	switch (k) {
	case 0:
		for (int i = 0; i < s + 3; i++)printf(" ");
		break;
	case 1:
		printf(" ");
		for (int i = 0; i < s; i++) {
			printf("-");
		}
		printf("  ");
		break;
	case 2:
		for (int i = 0; i < s + 1; i++)
			printf(" ");
		printf("| ");
		break;
	case 3:
		printf("|");
		for (int i = 0; i < s + 2; i++)
			printf(" ");
		break;
	case 4:
		printf("|");
		for (int i = 0; i < s; i++)
			printf(" ");
		printf("| ");
		break;
	default:
		break;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int idx = 0;
	scanf("%d", &s);
	while (scanf("%1d", &arr[idx++]) != EOF); idx--;
	for (int i = 0; i < idx; i++)
		func(lcd[0][arr[i]]);
	printf("\n");
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < idx; i++)
			func(lcd[1][arr[i]]);
		printf("\n");
	}
	for (int i = 0; i < idx; i++)
		func(lcd[2][arr[i]]);
	printf("\n");
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < idx; i++)
			func(lcd[3][arr[i]]);
		printf("\n");
	}
	for (int i = 0; i < idx; i++)
		func(lcd[4][arr[i]]);
	printf("\n");
	return 0;
}