#include <iostream>
#include <string>
using namespace std;
int n, m, l[105][105],pre[105][105];
string x, y, z,temp,ans;
int main() {
	cin >> x >> y>>z;
	for (int i = 0; i < x.length(); i++)
		for (int j = 0; j < y.length(); j++)
			if (x[i] == y[j]) {
				l[i + 1][j + 1] = l[i][j] + 1;
				pre[i + 1][j + 1] = 0;
			}
			else if (l[i][j + 1] > l[i + 1][j]) {
				l[i + 1][j + 1] = l[i][j + 1];
				pre[i + 1][j + 1] = 1;
			}
			else {
				l[i + 1][j + 1] = l[i + 1][j];
				pre[i + 1][j + 1] = 2;
			}
	int i = x.length(), j = y.length();
	while (i > 0 && j > 0) {
		switch (pre[i][j]) {
		case 0:
			ans.push_back(x[i - 1]);
			i--; j--;
			break;
		case 1:
			i--;
			break;
		case 2:
			j--;
			break;
		}
	}
	for (int i = 0; i < 100; i++)for (int j = 0; j < 100; j++)l[i][j] = 0;
	for (int i = 0; i < ans.length(); i++)
		for (int j = 0; j < z.length(); j++)
			if (ans[i] == z[j]) {
				l[i + 1][j + 1] = l[i][j] + 1;
				pre[i + 1][j + 1] = 0;
			}
			else if (l[i][j + 1] > l[i + 1][j]) {
				l[i + 1][j + 1] = l[i][j + 1];
				pre[i + 1][j + 1] = 1;
			}
			else {
				l[i + 1][j + 1] = l[i + 1][j];
				pre[i + 1][j + 1] = 2;
			}
	printf("%d", l[ans.length() - 1][z.length() - 1]);
	return 0;
}
//#include <cstdio>
//#include <vector>
//using namespace std;
//typedef struct { int x, y; }point;
//int arr[9][9],k=1,n[9][9];
//vector<point> s[9],v;
//void func(int dep) {
//	if (!k)return;
//	if (dep == v.size()) {
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++)
//				printf("%d", arr[i][j]);
//			printf("\n");
//		}
//		k = 0;
//		return;
//	}
//	point cur = v[dep];
//	int c = n[cur.y][cur.x];
//	for (int i = 1; i < 10; i++) {
//		bool b = 1;
//		for (int j = 0; j < 9; j++) {
//			if (arr[cur.y][j] == i)b = 0;
//			if (arr[j][cur.x] == i)b = 0;
//			if (arr[s[c][j].y][s[c][j].x] == i)b = 0;
//		}
//		if (!b)continue;
//		arr[cur.y][cur.x] = i;
//		func(dep + 1);
//		arr[cur.y][cur.x] = 0;
//	}
//}
//int main() {
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++) {
//			scanf("%1d", &arr[i][j]);
//			if (!arr[i][j])v.push_back({ j,i });
//			int num = 0;
//			if (i < 3) {
//				if (j < 3)num = 0;
//				else if (j < 6)num = 1;
//				else num = 2;
//			}
//			else if (i < 6) {
//				if (j < 3)num = 3;
//				else if (j < 6)num = 4;
//				else num = 5;
//			}
//			else {
//				if (j < 3)num = 6;
//				else if (j < 6)num = 7;
//				else num = 8;
//			}
//			s[num].push_back({ j,i });
//			n[i][j] = num;
//		}
//	func(0);
//	return 0;
//}