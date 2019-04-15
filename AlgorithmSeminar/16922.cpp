#include <cstdio>
int N, num[] = { 1, 5, 10, 50 }, cnt;
bool map[21][1001];
void func(int n, int val) {
	if (map[n][val])return;
	map[n][val] = 1;
	if (n == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < 4; i++)func(n + 1, val + num[i]);
}
int main() {
	scanf("%d", &N);
	func(0, 0);
	printf("%d", cnt);
	return 0;
}