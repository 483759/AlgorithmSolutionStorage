#include <cstdio>
bool visit[155];
int n,k,m,arr[155];
int main() {
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	int i = 0;
	while (i != k) {
		m++;
		if (visit[i])break;
		
		visit[i] = 1;
		i = arr[i];		
	}
	if (i == k)printf("%d", m);
	else printf("-1");
	return 0;
}

//#include <cstdio>
//int arr[2][205], n, k,ans,idx;
//int count() {
//	int sum = 0;
//	for (int i = 0; i < 2 * n; i++)
//		if (arr[1][i] <= 0)sum++;
//	return sum;
//}
//void print(int t) {
//	for (int i = 0; i < n; i++) {
//		printf("%2d", arr[0][(i + t) % (2 * n)]);
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		printf("%2d", arr[1][(i + t) % (2 * n)]);
//	}
//	printf("\n");
//	for (int i = 2*n-1; i >=n; i--) {
//		printf("%2d", arr[1][(i + t) % (2 * n)]);
//	}
//	printf("\n");
//	for (int i = 2 * n - 1; i >= n; i--) {
//		printf("%2d", arr[0][(i + t) % (2 * n)]);
//	}
//	printf("\n\n");
//}
//int main() {	//arr[0] = 로봇 유무, arr[1] = 내구도
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < 2 * n; i++)scanf("%d", &arr[1][i]);
//
//	while (++ans) {
//		arr[0][(idx + n - 1) % (2 * n)] = 0;
//		idx = (idx - 1 + 2 * n) % (2 * n);
//
//		
//		for (int i = n-1; i >= 0; i--) {
//			int cur = (idx + i) % (2 * n);
//			if (i == n - 1) {
//				arr[0][cur] = 0;
//				continue;
//			}
//			if (!arr[0][cur])continue;
//
//			int next = (cur + 1) % (2 * n);
//			if (!arr[0][next] && arr[1][next] >= 1) {
//				arr[0][next] = 1;
//				arr[0][cur] = 0;
//				arr[1][next]--;
//			}
//		}
//		if (arr[0][idx] == 0 && arr[1][idx] >= 1) {
//			arr[0][idx] = 1;
//			arr[1][idx]--;
//		}
//		if (count() >= k)break;
//	}
//
//	printf("%d", ans);
//	return 0;
//}