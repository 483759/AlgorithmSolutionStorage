//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n;
//int arr[10001];
//int val[10001];
//int func(int N, int cnt) {
//	if (!N)return 0;
//	if (N == 1)return val[1];
//	int& ref = arr[N];
//	//if (ref != -1)return arr[N];
//	if (cnt == 2) return ref = val[N] + func(N - 2, 0);
//	return ref = val[N] + max(func(N - 1, cnt + 1), func(N - 2, 0));
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &val[i]);
//	fill(arr, arr + 10001, -1);
//	printf("%d", func(n, 0));
//	return 0;
//}

#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int val[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

}