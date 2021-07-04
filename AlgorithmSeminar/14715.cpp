#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	v.assign(5, 0);	//0,0,0,0,0 할당

	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << ' ';
	cout << '\n';

	v.clear();
	if (v.empty())	//clear했기 때문에 1반환
		cout << "Empty\n";

	for (int i = 1; i <= 6; i++)
		v.push_back(i);	//1~6까지의 원소 삽입
	v.pop_back();	//마지막 원소 제거(6)

	cout << "Front: " << v.front() << '\n';
	cout << "Back: " << v.back() << '\n';
	//처음과 마지막 원소 출력

	return 0;
}

//#include <cstdio>
//int k,n,sum[100005],ans,g[100005];
//void func(int dep) {
//	if (dep > k) {
//		int min = 987654321;
//		for (int i = 1,sub; i <= k; i++) {
//			sub = sum[g[i]] - sum[g[i - 1]];
//			if (sub < min)min = sub;
//		}
//		if (min > ans)ans = min;
//		return;
//	}
//	for (int i = dep; i <= n - k + dep; i++) {
//		g[dep] = i;
//		func(dep + 1);
//	}
//}
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 1,a; i <= n; i++) {
//		scanf("%d", &a);
//		sum[i] = sum[i - 1] + a;
//	}
//	func(1);
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int k, arr[1000], ans, t;
//bool b[1000001];
//int main() {
//	scanf("%d", &k);
//	memset(b, true, sizeof(b)); b[0] = b[1] = false;
//	for (int i = 2; i <= 1000; i++)
//		if (b[i]) {
//			for (int j = i + i; j <= 1000000; j += i)
//				b[j] = false;
//		}
//	if (b[k]) {
//		printf("0"); return 0;
//	}
//	for (int i = 2; i <= 1000; i++)
//		while (!(k % i)) {
//			arr[i]++; k /= i; t++;
//		}
//	printf("%d", t % 2 ? (t + 1) / 2 : t / 2);
//	return 0;
//}