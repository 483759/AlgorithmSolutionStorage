#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL));
	FILE* fp = fopen("\\input\\sample_1.in", "w");
	fprintf(fp, "20\n");
	for (int i = 0; i < 20; i++)
		fprintf(fp, "%d ", (rand() % 7) +1);
	return 0;
}