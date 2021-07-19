#include <cstdio>
#include <algorithm>
int n,val[30];
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &val[i]);
	std::sort(val, val + n, cmp);
	for (int i = 0; i < n; i++)printf("%d ", val[i]);
	return 0;
}
//#include <cstdio>
//int n, m, val[101][101], max, ans;
//int main() {
//	freopen("input.txt","r",stdin);
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)scanf("%d", &val[i][j]);
//	for (int i = 0; i < n; i++)
//		for (int j = 0, pre=0; j < m; j++) {
//			if (val[i][j] > pre)
//				ans += val[i][j] - pre;
//			pre = val[i][j];
//		}
//	for (int i = 0; i < m; i++)
//		for (int j = 0, pre = 0; j < n; j++) {
//			if (val[j][i] > pre)
//				ans += val[j][i] - pre;
//			pre = val[j][i];
//		}
//	for (int i = 0; i < n; i++)
//		for (int j = m - 1, pre = 0; j >= 0; j--) {
//			if (val[i][j] > pre)
//				ans += val[i][j] - pre;
//			pre = val[i][j];
//		}
//	for (int i = m - 1; i >= 0; i--)
//		for (int j = n - 1, pre = 0; j >= 0; j--) {
//			if (val[j][i] > pre)
//				ans += val[j][i] - pre;
//			pre = val[j][i];
//		}
//	ans += n * m * 2;
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//int n, m, val[101][101], h, ans;
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)scanf("%d", &val[i][j]);
//	for (int i = 0; i < n; i++)
//		for (int j = 0, pre = 0; j < m; j++) {
//			if (val[i][j] > pre)
//				ans += val[i][j] - pre;
//			pre = val[i][j];
//		}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0, pre = 0; j < m; j++) {
//			if (val[j][i] > pre)
//				ans += val[j][i] - pre;
//			pre = val[j][i];
//		}
//	}
//	for (int i = 0; i < n; i++)
//		for (int j = m - 1, pre = 0; j >= 0; j--) {
//			if (val[i][j] > pre)
//				ans += val[i][j] - pre;
//			pre = val[i][j];
//		}
//	for (int i = n - 1; i >= 0; i--)
//		for (int j = m - 1, pre = 0; j >= 0; j--) {
//			if (val[j][i] > pre)
//				ans += val[j][i] - pre;
//			pre = val[j][i];
//		}
//	ans += n * m * 2;
//	printf("%d", ans);
//	return 0;
//}