#include <cstdio>
#include <algorithm>
using namespace std;
bool chk[1000];
int n, ans, t;
int main() {
	fill(chk, chk + 1000, true);
	scanf("%d", &n);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0, k = i; j < 3; j++) {
			if (!(k % 10))chk[i] = false;
			k /= 10;
		}
	}
	for (int i = 0; i < n; i++) {
		int num[3], s, b;
		scanf("%d%d%d", &t, &s, &b);
		num[0] = t / 100; num[1] = (t / 10) % 10; num[2] = t % 10;
		for (int j = 111; j < 1000; j++) {
			if (!chk[j])continue;
			int a[3], cs = 0, cb = 0;
			a[0] = j / 100; a[1] = (j / 10)%10; a[2] = j % 10;
			if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
				chk[j] = false;
				continue;
			}
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if (k == l && num[k] == a[l])cs++;
					else if (num[k] == a[l])cb++;
				}
			if (cs != s || cb != b)chk[j] = false;
		}
	}
	for (int i = 0; i < 1000; i++)
		if (chk[i]) ans++;
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//bool arr[1000];
//int n, num, s, b, on[3], nn[3];
//bool func(int i, int arr[]) {
//	int k = 2;
//	while (i) {
//		if (i % 10 == 0)
//			return true;
//		arr[k--] = num % 10;
//		i /= 10;
//	}
//	return false;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int on[3];
//		scanf("%d %d %d", &num, &s, &b);
//		func(num, on);
//		for (int i = 111; i <= 999; i++) {
//			if (func(i, nn))continue;
//			}
//	}
//}