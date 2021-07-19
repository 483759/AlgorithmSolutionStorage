#include <cstdio>
int N, cnt;
int main() {
	scanf("%d", &N);
	while (N > 0) {
		if (N % 5 == 0) {
			cnt += N / 5;
			N = 0;
			break;
		}
		else {
			cnt++;
			N -= 3;
		}
	}
	if (!N)printf("%d", cnt);
	else printf("-1");
	return 0;
}