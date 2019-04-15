#include <cstdio>
#include <string.h>
int L, C, j;
bool apb[27];
char c[16];

bool isVew(char K) {
	bool a;
	switch (K) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		a = true;
		break;
	default:
		a= false;
		break;
	}
	return a;
}
void func(char *str, int idx, int con, int vew) {
	char s[16] = { NULL }, K;
	if (con + vew == L) {
		if (con >= 2 && vew >= 1)
			printf("%s\n", str);
		return;
	}
	K = c[idx];
	if (!con && !vew)
		s[0] = c[idx];
	else {
		strcpy(s, str);
		s[con + vew] = c[idx];
	}
	if (isVew(c[idx]))vew++;
	else con++;
	for (int i = idx; i < C; i++)
		func(s, idx + 1, con, vew);
}
int main() {
	freopen("input.txt", "r", stdin);
	char K;
	scanf("%d%d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &K);
		apb[K - 'a'] = true;
	}
	for (int i = 0; i < 27; i++) {
		if (apb[i])
			c[j++] = i + 'a';
	}
	c[j] = '\n';
	func(NULL, 0, 0, 0);
	return 0;
}