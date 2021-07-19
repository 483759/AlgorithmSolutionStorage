#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v;
int n,ans;
int main() {
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k || k == i)continue;
				vector<int> arr = { i,j,k,1 };
				v.push_back(arr);
			}

	scanf("%d", &n);
	while (n--) {
		int k, b, s;
		scanf("%d%d%d", &k, &s, &b);

		int arr[] = { k / 100,(k / 10) % 10,k % 10 };

		for (int t = 0; t < v.size(); t++) {
			if (!v[t][3])continue;
			int cs=0, cb=0;

			for (int j = 0; j < 3; j++)
				if (v[t][j] == arr[j])cs++;

			for(int i=0;i<3;i++)
				for (int j = 0; j < 3; j++) {
					if (i == j)continue;
					if (v[t][i] == arr[j])cb++;
				}
			if (cs != s || cb != b)v[t][3] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++)
		if (v[i][3])ans++;
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//
//typedef pair<int, int> pii;
//
//queue<pii> q;
//
//bool cmp(int a, int b) {
//	return a > b;
//}
//int main() {
//	int num, n, m;
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &num);
//
//	for (int i = 0; i < num; i++) {
//		int t, arr[100] = { 0 }, index = 0;
//		pii pi, tmp;
//		scanf("%d %d", &n, &m);
//
//		for (int j = 0; j < n; j++) {	//Å¥¿¡ »ðÀÔ
//			scanf("%d", &t);
//			q.push(pii(t, j));
//		}
//
//		for (int j = 0; j < n; j++) {
//			if (q.front().second == m)
//				pi = q.front();
//			arr[j] = q.front().first;
//			q.push(q.front());
//			q.pop();
//		}
//
//		sort(arr, arr + n, cmp);
//
//		while (!q.empty()) {
//			while (q.front().first != arr[index]) {
//				q.push(q.front());
//				q.pop();
//			}
//			tmp = q.front();
//			q.pop();
//			index++;
//			if (tmp == pi)
//				break;
//		}
//
//		printf("%d\n", index);
//
//		while (!q.empty())
//			q.pop();
//	}
//	return 0;
//}