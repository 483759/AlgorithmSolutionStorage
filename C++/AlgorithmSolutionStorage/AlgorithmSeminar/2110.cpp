#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m, l, ans=1005;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &l);

	v.push_back(0); 
	for (int i = 0,p; i < n; i++) {
		scanf("%d", &p);
		v.push_back(p);
	}
	v.push_back(l);

	sort(v.begin(), v.end());
	int left = 0, right = l-1;

	while (left <= right) {
		int mid = (left + right) / 2;

		int size = v.size(),cnt=0,max=0;
		for (int i = 1; i < size; i++) {
			if (v[i] - v[i - 1] >= mid) {
				int quotient = (v[i] - v[i - 1]) / mid;
				int remainder = (v[i] - v[i - 1]) % mid;
				if (remainder)
					cnt += quotient;
				else cnt += quotient - 1;
				
			}
		}
		if (cnt > m) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d", left);

	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#define ull unsigned long long
//using namespace std;
//
//int n, c;
//ull home[200005],ans;
//
//int main() {
//	scanf("%d%d", &n, &c);
//	for (int i = 0; i < n; i++)scanf("%lld", &home[i]);
//
//	sort(&home[0], &home[n]);
//	ull left = 0, right = home[n-1]-home[0];
//	
//	while (left <= right) {
//		ull mid = (left + right) / 2;
//
//		ull min = 0,cnt=1;
//		for (int i = 0; i < n; i++) {
//			if (home[i] - home[min] >= mid) {
//				min = i;
//				cnt++;
//			}
//		}
//
//		if (cnt>=c) {
//			left = mid + 1;
//			if (mid > ans)ans = mid;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//	printf("%lld", ans);
//	return 0;
//}