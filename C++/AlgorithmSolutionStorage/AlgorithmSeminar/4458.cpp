#include <cstdio>
#include <string>
int N;
char str[31];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %[^\n]s", str);
		str[0]=toupper(str[0]);
		printf("%s\n", str);
	}
	return 0;
}