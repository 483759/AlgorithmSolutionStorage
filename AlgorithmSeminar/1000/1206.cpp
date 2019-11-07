#include <cstdio>
#define max(a,b) a>b?a:b
int arr[1001], l, ans,m;
int main() {
	for (int T = 0; T < 10; T++) {
		scanf("%d", &l); ans = 0;
		for (int i = 0; i < l; i++)scanf("%d", &arr[i]);
		
		m = max(arr[3], arr[4]);
		for (int i = 2; i < l - 2; i++) {
			m = max(arr[i - 2], arr[i - 1]);
			m = max(m, arr[i + 1]);
			m = max(m, arr[i + 2]);

			if (arr[i] > m)ans += arr[i] - m;			
		}
		printf("%d\n", ans);
	}
	return 0;
}