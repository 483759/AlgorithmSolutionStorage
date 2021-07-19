//#include <cstdio>
//#include <vector>
//using namespace std;
//
//
//int main() {
	/* 원하는 길이만큼 잘라서 입력받기 */
	//int arr[21], N;
	//scanf("%d", &N);

	//for (int i = 0; i < N; i++)
	//	scanf("%1d", &arr[i]);
	//for (int i = 0; i < N; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");
	//return 0;

	/* scanf()버퍼 지우기 */
	//int n, c;
	//scanf("%d", &n);
	//scanf(" %c", &c);
	//printf("%d\n", n);
	//printf("%c\n", c);
	//return 0;

	/* 개수가 정해지지 않은 입력 받기 */
	//int cnt = 0, a;
	//freopen("input.txt", "r", stdin);
	//while (scanf("%d", &a) != EOF)
	//	cnt++;
	//printf("%d\n", cnt);
	//return 0;
	//int sum, tmp;
	//vector<int> vec;
	//while (scanf("%d", &tmp) != EOF)
	//	vec.push_back(tmp);

	//sum = vec.back();	vec.pop_back();
	//for (int i = 0; i < vec.size() - 1; i++)
	//	for (int j = 0; j < vec.size(); j++)
	//		if (vec[i] + vec[j] == sum) {
	//			printf("%d %d\n", i, j);
	//			return 0;
	//		}
	//return 0;


//}

/* 카운팅 정렬 */
//#include <cstdio>
//int arr[100];
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int i = 0, t; i < 10; i++) {
//		scanf("%d", &t);
//		arr[t]++;
//	}
//
//	for (int i = 0; i < 100; i++) {
//		if (arr[i] != 0)
//			printf("%d ", i);
//	}
//	printf("\n");
//	return 0;
//}

#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("input.txt", "r", stdin);
	int arr[10];
	for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);

	sort(arr, arr + 10, cmp);

	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;

}

/* 파스칼 삼각형 */
//#include <cstdio>
//
//int dp[100][100];
//
//int comb(int n, int k) {
//	int& ret = dp[n][k];
//	if (k == 0 || k == 1)
//		return ret = 1;
//	if (ret) return dp[n][k];
//	return ret = comb(n - 1, k - 1) + comb(n - 1, k);
//}
//
//int main() {
//
//	return 0;
//}

//#include <iostream>
//#define fi first
//#define se second
//using namespace std;
//typedef pair<int, int> pii;
//
//int main() {
//
//	pii p;
//	pii p2(3, 4);
//	pair<pii, pii> p3 = { {5, 6}, {7, 8} };
//	p = { 1, 2 };
//	printf("%d %d\n", p.fi, p.se);
//	printf("%d %d\n", p2.first, p2.second);
//
//	return 0;
//}