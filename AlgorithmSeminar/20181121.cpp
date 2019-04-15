#include <cstdio>
int func(int N, int C) {
	int cnt[3] = { 99999, 99999, 99999 }, min;
	if (N == 1)
		return 1;
	if (!(N % 3))
		cnt[0] = func(N / 3, C);
	if (!(N % 2))
		cnt[1] = func(N / 2, C);
	cnt[2] = func(N - 1, C);
	min = (cnt[0] > cnt[1]) ? cnt[0] : cnt[1];
	min = (cnt[2] > min) ? cnt[2] : min;
	return min;
}
int main() {

}

//#include <cstdio>
//int n, r;
//int C[101][101];
//int combination(int N, int R) {
//	if (!R || N == R)
//		return 1;
//	int& ref = C[N][R];
//	if (ref) return ref;
//	return ref= combination(N - 1, R - 1) + combination(N - 1, R);
//}
//int main() {
//	scanf("%d%d", &n, &r);
//	printf("%d", combination(n, r));
//	return 0;
//}