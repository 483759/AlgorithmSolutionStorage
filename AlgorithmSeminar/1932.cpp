#include <cstdio>
#include <algorithm>
using namespace std;
char s[1000001];
struct t { int a, n; };
t arr[26];
bool cmp(t a, t b) {
	return a.n > b.n;
}
int main() {
	scanf("%s", s);
	for (int i = 0; i < 26; i++)arr[i].a = i;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] <= 'Z')arr[s[i] - 'A'].n++;
		else arr[s[i] - 'a'].n++;
	}
	sort(arr, arr + 26, cmp);
	if (arr[0].n == arr[1].n)printf("?");
	else printf("%c", arr[0].a + 'A');
	return 0;
}