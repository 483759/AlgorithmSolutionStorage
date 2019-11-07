#include <cstdio>
char c,p;
int ans,s;
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%c", &c) != EOF && c!='\0' && c!='\n') {
		if (c == '(') s++;
		else {
			s--;
			if (p == '(') ans += s;
			else ans++;
		}
		p = c;
	}
	printf("%d", ans);
	return 0;
}