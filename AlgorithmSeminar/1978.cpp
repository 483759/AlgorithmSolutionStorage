#include <cstdio>

bool num[1001] = {true, true};
int N, n[101], cnt;

void func() {
	for (int i = 2; i <= 1001; i++)
		for (int j = i+i; j <= 1001; j += i)
			num[j] = true;
}

int main() {
	func();
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &n[i]);

	for (auto i :n)
		if (!num[i])cnt++;

	printf("%d", cnt);
	return 0;
}