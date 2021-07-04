//#include <cstdio>
//#include <algorithm>
//#define ull unsigned long long
//using namespace std;
//
//int his[100005], n;
//
//ull histogram(int left, int right) {
//	if (left == right) {
//		return his[left];
//	}
//	int mid = (left + right) / 2;
//	ull ret = max(histogram(left, mid), histogram(mid + 1, right));
//
//	ull s = mid, e = (ull)mid + 1, h;
//	h = min(his[s], his[e]);
//	ret = max(ret, h * (e - s + 1));
//
//	while (s > left || e < right) {
//		if (e < right && (s == left || his[s - 1] < his[e + 1])) {
//			e++;
//			h = min(h, (ull)his[e]);
//		}
//		else {
//			s--;
//			h = min(h, (ull)his[s]);
//		}
//		ret = max(ret, h * (e - s + 1));
//	}
//
//	return ret;
//}
//
//int main() {
//	while (1) {
//		scanf("%d", &n);
//		if (!n)break;
//		for (int i = 0; i < n; i++)scanf("%d", &his[i]);
//		printf("%lld\n", histogram(0, n - 1));
//	}
//	return 0;
//}