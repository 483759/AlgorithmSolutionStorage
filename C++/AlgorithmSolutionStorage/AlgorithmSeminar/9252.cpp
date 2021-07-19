#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int n,bound;
	scanf("%d", &n);
	bound = n * (n + 1) / 2;
	vector<int> answer;
	int arr[1005][1005] = { 0 };
	int st = 0, num = 1, cx = 0, cy = 0;
	while (num<=bound) {
		arr[cy][cx] = num++;
		switch (st) {
		case 0:
			if ((cy + 1 >= n) || arr[cy + 1][cx])st = 1;
			else {
				cy++;
				break;
			}
		case 1:
			if ((cx + 1 >= n) || arr[cy][cx + 1])st = 2;
			else {
				cx++;
				break;
			}
		case 2:
			if ((cy < 1 || cx < 1) || arr[cy - 1][cx - 1]) {
				cy++;st = 0;
			}
			else {
				cx--; cy--;
			}
			break;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			answer.push_back(arr[i][j]);
			printf("%d ", arr[i][j]);
		}
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//int n, m, l[7005][7005], pre[7005][7005];
//string x, y, ans;
//int main() {
//	cin >> x >> y;
//	x.insert(x.begin(), '0');
//	y.insert(y.begin(), '0');
//	for (int i = 1; i < x.length(); i++)
//		for (int j = 1; j < y.length(); j++)
//			if (x[i] == y[j]) {
//				l[i][j] = l[i - 1][j - 1] + 1;
//				pre[i][j] = 0;
//			}
//			else if (l[i - 1][j] > l[i][j - 1]) {
//				l[i][j] = l[i - 1][j];
//				pre[i][j] = 1;
//			}
//			else {
//				l[i][j] = l[i][j - 1];
//				pre[i][j] = 2;
//			}
//	int i = x.length()-1, j = y.length()-1;
//	while (i > 0 && j > 0) {
//		switch (pre[i][j]) {
//		case 0:
//			ans.push_back(x[i]);
//			i--; j--;
//			break;
//		case 1:
//			i--;
//			break;
//		case 2:
//			j--;
//			break;
//		}
//	}
//	cout << ans.length() << '\n';
//	for (int i = ans.length() - 1; i >= 0; i--)
//		printf("%c", ans[i]);
//	return 0;
//}