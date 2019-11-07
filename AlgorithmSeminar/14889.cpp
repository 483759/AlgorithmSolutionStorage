#include <cstdio>
int n, s[21][21], ans=10000000;
bool b[21];
void func(int dep, int last) {
	if (dep == n / 2) {
		int start = 0, link = 0, sub;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (b[i] && b[j])start += s[i][j];
				else if(!b[i]&&!b[j]) link += s[i][j];
			}
		sub = start > link ? start - link : link - start;
		if (sub < ans)ans = sub;
		return;
	}
	for (int i = last + 1; i < n / 2 + 1 + dep; i++) {
		b[i] = true;
		func(dep + 1, i);
		b[i] = false;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &s[i][j]);
	func(0, -1);
	printf("%d", ans);
	return 0;
}

//for (int i = 0; i < n - 2; i++)
//	for (int j = 1; j < n - 1; j++)
//		for (int k = 2; k < n; k++)