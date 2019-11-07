#include <cstdio>
int n, m, sum, min = 10000;
bool arr[10001] = { 0,1 };
int main() {
	for (int i = 2; i <= 100; i++) {
		for (int j = i * 2; j <= 10000; j += i)
			arr[j] = true;
	}
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++)
		if (!arr[i]) {
			sum += i;
			min = i < min ? i : min;

		}
	if(sum)printf("%d\n%d", sum, min);
	else printf("-1");
	return 0;
}
//#include <cstdio>
//#include <vector>
//using namespace std;
//int n, p[11];
//vector<int> v[11];
//bool connect[10][10], visit[11];
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);
//	for (int i = 1, t; i <= n; i++) {
//		scanf("%d", &t);
//		v[i].push_back(t);
//	}
//	return 0;
//}