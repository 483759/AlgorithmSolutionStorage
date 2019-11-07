#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m,t;
vector<int> v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		int s = 0, f = v.size() - 1, m = (s + f) / 2;
		while (s <= f) {
			if (t > v[m])s = m + 1;
			else if (t < v[m])f = m - 1;
			else break;
			m = (s + f) / 2;
		}
		printf("%d ", s <= f ? 1 : 0);
	}
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n, l, i, j,k, map[101][101], ans, cnt, a;
//bool v[101][101], d;
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &l);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%d", &map[i][j]);
//
//	//for (i = 0; i < n; i++) {
//	//	for (j = 0, cnt = 0; j < n-1; j++) {
//	//		if (map[i][j] == map[i][j + 1]) {
//	//			cnt++; continue;
//	//		}
//	//		else if (map[i][j] < map[i][j + 1]) {
//	//			if (cnt < l)break;
//	//			continue;
//	//		}
//	//		else {
//	//			for (k = 0; k < l; k++)
//	//				if (map[i][j + 1] != map[i][j + 1 + k]||(j+1+k>=n))
//	//					break;
//	//			if (k != l)break;
//	//			j += k-1;
//	//		}
//	//	}
//	//	if (j >= n-1)ans++;
//	//}
//
//	for (i = 0; i < n; i++) {
//		for (j = 0, cnt = 0; j < n - 1; j++) {
//			printf("%2d ", map[i][j + 1] - map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d", ans);
//	return 0;
//}
//-1-1 011
//-1 0-111
//-1 0 010
// 0 0 000
// 0 0 0-10