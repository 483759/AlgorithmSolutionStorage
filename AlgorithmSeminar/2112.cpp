#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, arr[1000001];
int dp[1000001];
int cut(int k) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > k)sum += arr[i] - k;
	return sum;
}
void binary(int s, int t) {
	int mid = (s + t / 2);
	if (dp[mid])return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	//for (int i = 0; i < n; i++)
	//	printf("%d", arr[i]);

	return 0;
}
//fill(&arr[0][0], &arr[ROW - 1][COL], value)
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	for (int i = 1; i <= 6; i++)
		v.push_back(i);	//1~6까지의 원소 삽입

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << '\n';
	//iterator를 이용한 원소 출력

	it = v.begin() + 2;
	v.insert(it, 0);	//3번째 원소 위치에 0 삽입
	it = v.begin() + 3;
	v.erase(it);	//4번째 원소 삭제(3)

	for (it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << '\n';

	return 0;
}

//#include <cstdio>
//#include <stack>
//using namespace std;
//int tc, d, w, k, ans, ins;
//bool f[14];
//bool map[14][21];
//bool continous() {
//	stack<bool> a, b;
//	for (int j = 0,i; j < w; j++) {
//		for (i = 0; i < d; i++) {
//			if (a.size() >= k || b.size() >= k) {
//				while (!a.empty())a.pop();
//				while (!b.empty())b.pop();
//				break;
//			}
//			if (f[i]) {
//				a.push(1); b.push(1);
//			}
//			else if (map[i][j]) {
//				b.push(1);
//				while (!a.empty())a.pop();
//			}
//			else {
//				a.push(1);
//				while (!b.empty())b.pop();
//			}
//				
//		}
//		if (i == d)return false;
//	}
//	return true;
//}
//void simulator(int t, int dep) {
//	if (ans != -1)return;
//	if (dep == ins) {
//		if (continous())
//			ans = ins;
//		return;
//	}
//
//	bool temp[21];
//	for (int i = t; i < d; i++) {
//		f[i] = 1;
//		simulator(i + 1, dep + 1);
//		f[i] = 0;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int T = 1; T <= tc; T++) {
//		ans = -1; ins = 0;
//		scanf("%d%d%d", &d, &w, &k);
//		for (int i = 0; i < d; i++)
//			for (int j = 0, a; j < w; j++)
//				scanf("%d", &map[i][j]);
//
//		while (ans == -1 && !continous()) {
//			ins++;
//			simulator(0, 0);
//		}
//
//		printf("#%d %d\n", T, ans == -1 ? 0 : ans);
//	}
//	return 0;
//}