#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int hanoi(int n, int from, int by, int to) {
	int count = 1;
	if (n == 1)
		v.push_back({ from,to });
	else {
		count+=hanoi(n - 1, from, to, by);
		v.push_back({ from,to });
		count+=hanoi(n - 1, by, from, to);
	}
	return count;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n",hanoi(n, 1, 2, 3));
	for (auto x : v)printf("%d %d\n", x.first, x.second);
	return 0;
}
//#include <cstdio>
//#include <vector>
//using namespace std;
//typedef struct { int r,c; }point;
//int map[9][9];
//vector<point> v;
//bool f,row[10][10], col[10][10], sqr[10][10];
//int zone(int r, int c) {
//	if (r < 3)return (c / 3) + 1;
//	if (r < 6)return (c / 3) + 4;
//	return (c / 3) + 7;
//}
//void func(int dep) {
//	if (f)return;
//	if (dep == v.size()) {
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++)
//				printf("%d ", map[i][j]);
//			printf("\n");
//		}f = 1;
//		return;
//	}
//	point cur = v[dep];
//	for (int i = 1; i <= 9; i++) {
//		if (row[cur.r][i]|| col[cur.c][i]
//			|| sqr[zone(cur.r, cur.c)][i])continue;
//		map[cur.r][cur.c] = i;
//		row[cur.r][i] = 1;
//		col[cur.c][i] = 1;
//		sqr[zone(cur.r, cur.c)][i] = 1;
//
//		func(dep + 1);
//
//		map[cur.r][cur.c] = 0;
//		row[cur.r][i] = 0;
//		col[cur.c][i] = 0;
//		sqr[zone(cur.r, cur.c)][i] = 0;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++) {
//			scanf("%d", &map[i][j]);
//			if (!map[i][j])v.push_back({ i,j });
//			else {
//				row[i][map[i][j]] = 1;
//				col[j][map[i][j]] = 1;
//				sqr[zone(i, j)][map[i][j]] = 1;
//			}
//		}
//	func(0);
//	return 0;
//}