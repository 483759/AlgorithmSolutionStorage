#include <cstdio>
#include <cstring>
int t;
char s[81];
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int ans = 0, count = 1;
		scanf("%s", s);
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'X') {
				count = 1;
				continue;
			}
			ans += count;
			count++;
		}
		printf("%d\n", ans);
	}
	return 0;
}