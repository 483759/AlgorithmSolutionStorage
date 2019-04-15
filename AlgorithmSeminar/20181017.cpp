#include <cstdio>
int N, S, a[21], cnt;
void func(int idx, int sum) {
	if (idx && sum == S)cnt++;
	if (idx == N)return;
	for (int i = idx; i < N; i++) {
		func(i + 1, sum + a[i]);
	}
}
int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++)scanf("%d", &a[i]);
	func(0, 0);
	printf("%d", cnt);
	return 0;
}