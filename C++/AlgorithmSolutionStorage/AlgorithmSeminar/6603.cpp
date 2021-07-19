#include <cstdio>
int k;
bool b[14];
void func(int arr[], int dep, int cnt) {
	if (dep > k||k-dep+cnt<6)return;
	if (cnt==6) {
		for (int i = 0; i < 14; i++)
			if (b[i])printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	b[dep] = true;
	func(arr, dep + 1, cnt+1);
	b[dep] = false;
	func(arr, dep + 1, cnt);
	return;
}
int main() {
	while (1) {
		int s[14];
		scanf("%d", &k);
		if (!k)return 0;

		for (int i = 0; i < k; i++)scanf("%d", &s[i]);
		func(s, 0, 0);
	}
	return 0;
}
//#include <cstdio>
//int k, s[14];
//void dfs(int n) {
//	printf("%d")
//		for (int i = n; i < k; i++)
//			dfs(i);
//}
//int main() {
//	while (1) {
//		scanf("%d", &k);
//		if (!k)return 0;
//		for (int i = 0; i < k; i++)scanf("%d", &s[i]);
//	}
//	return 0;
//}