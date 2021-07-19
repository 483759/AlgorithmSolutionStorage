#include <cstdio>
int tc, r, c, path[21][21][4][16], dx[] = { 1,0,-1,0 }, dy[] = {0,1,0,-1};
int d,mem,ans;
char str[21][21];
void func(char c) {
	switch (c) {
	case '<':
		d = 0; break;
	case '>':
		d = 2; break;
	case '^':
		d = 3; break;
	case 'v':
		d = 1; break;
	case '_':
		if (!mem)d = 2;
		else d = 0;
		break;
	case '|':
		if (!mem)d = 1;
		else d = 3;
		break;
	case '?':
		break;
	case '@':
		printf("YES"); ans = 1;
		break;
	case '+':
		mem = (mem + 1) % 15;
		break;
	case '-':
		mem = (mem + 14) % 15;
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		mem = c - '0';
		break;
	case '.':
	default:
		break;
	}
}
int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++)scanf("%s", &str[i]);

		printf("#%d %s", t, ans ? "YES" : "NO");
	}
	return 0;
}