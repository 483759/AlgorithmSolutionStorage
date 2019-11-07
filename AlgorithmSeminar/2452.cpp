#include <cstdio>
#include <algorithm>
using namespace std;
int arr[51], b[51], n;
bool chk[51];
int main() {
	scanf("%d", &n);
	for (int i = 0,t; i < n; i++) {
		scanf("%d", &t);
		arr[i] = b[i] = t;
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i] == b[j]&&!chk[j]) {
				printf("%d ", j);
				chk[j] = true;
				break;
			}
	return 0;
}
//#include <cstdio>
//int n, m,arr[101][101];
//int main() {
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++) 
//		for (int j = 0; j < n; j++)
//			scanf("%d", &arr[i][j]);
//
//	return 0;
//}