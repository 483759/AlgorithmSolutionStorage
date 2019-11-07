#include <cstdio>
bool arr[5][5][5];
int main() {
	for (int k = 0; k < 5; k++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				scanf("%d", &arr[k][i][j]);

	return 0;
}