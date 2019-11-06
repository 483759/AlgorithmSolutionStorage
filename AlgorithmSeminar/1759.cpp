#include <cstdio>
char s;
int a, b, c, d,t;
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%c", &s) != EOF) {
		t = 0;
		if (s == '\n') {
			printf("%d %d %d %d\n", a, b, c, d);
			a = b = c = d = 0; t = 1;
		}
		else if (s == ' ')d++;
		else if (s >= 'a'&&s <= 'z')a++;
		else if (s >= 'A'&&s <= 'Z')b++;
		else c++;
	}
	if(!t)printf("%d %d %d %d\n", a, b, c, d);
	return 0;
}
//#include <cstdio>
//int L, C, j;
//bool apb[26],a[26], vew[26] = { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1 };
//char str[18];
//void func(int d, int c, int v, int s) {
//	if (d == L) {
//		if (c < 2 || v < 1)return;
//		for(int i=0;i<26;i++)if(a[i])printf("%c",i+'a');
//		printf("\n");
//		return;
//	}
//	for (int i = s; i < C; i++) {
//		a[str[i]-'a'] = 1;
//		if (vew[str[i] - 'a'])func(d + 1, c, v + 1, i + 1);
//		else func(d + 1, c + 1, v, i + 1);
//		a[str[i] - 'a'] = 0;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	char K;
//	scanf("%d%d", &L, &C);
//	for (int i = 0; i < C; i++) {
//		scanf(" %c", &K);
//		apb[K - 'a'] = true;
//	}
//	for (int i = 0; i < 26; i++) {
//		if (apb[i])
//			str[j++] = i + 'a';
//	}
//	str[j] = '\n';
//	func(0, 0, 0,0);
//	return 0;
//}
//#include <cstdio>
//#include <string.h>
//int L, C, j;
//bool apb[27];
//char c[16];
//
//bool isVew(char K) {
//	bool a;
//	switch (K) {
//	case 'a':
//	case 'e':
//	case 'i':
//	case 'o':
//	case 'u':
//		a = true;
//		break;
//	default:
//		a= false;
//		break;
//	}
//	return a;
//}
//void func(char *str, int idx, int con, int vew) {
//	char s[16] = { NULL }, K;
//	if (con + vew == L) {
//		if (con >= 2 && vew >= 1)
//			printf("%s\n", str);
//		return;
//	}
//	K = c[idx];
//	if (!con && !vew)
//		s[0] = c[idx];
//	else {
//		strcpy(s, str);
//		s[con + vew] = c[idx];
//	}
//	if (isVew(c[idx]))vew++;
//	else con++;
//	for (int i = idx; i < C; i++)
//		func(s, idx + 1, con, vew);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	char K;
//	scanf("%d%d", &L, &C);
//	for (int i = 0; i < C; i++) {
//		scanf(" %c", &K);
//		apb[K - 'a'] = true;
//	}
//	for (int i = 0; i < 27; i++) {
//		if (apb[i])
//			c[j++] = i + 'a';
//	}
//	c[j] = '\n';
//	func(NULL, 0, 0, 0);
//	return 0;
//}