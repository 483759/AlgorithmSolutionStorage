#include <cstdio>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;

ll n, m;
vector<vector<ll>> im;

vector<vector<ll>> matrixMultiply(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> c;
	for (size_t i = 0; i < a.size(); i++) {
		c.push_back(vector<ll>(a.size(), 0));
		for (size_t j = 0; j < b.size(); j++) {
			for (size_t k = 0; k < a.size(); k++)
				c[i][j] = //(c[i][j] + a[i][k] * b[k][j]);
			(((ll)c[i][j] % MOD) +
				((((ll)a[i][k] % MOD) * ((ll)b[k][j] % MOD)) % MOD)
				) % MOD;
		}
	}
	return c;
}

vector<vector<ll>> matrixSquared(vector<vector<ll>> a, ll k) {
	if (k == 0)return im;
	vector<vector<ll>> half = matrixSquared(a, k / 2);
	vector<vector<ll>> b = matrixMultiply(half, half);
	if (k % 2 == 0)return b;
	return matrixMultiply(b, a);
}


int main() {
	scanf("%lld%lld", &n, &m);
	vector<vector<ll>> a;
	a.push_back(vector<ll>(m));
	a[0][0] = a[0].back() = 1;
	for (int i = 0; i < m - 1; i++) {
		a.push_back(vector<ll>(m));
		a.back()[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		im.push_back(vector<ll>(m));
		im[i][i] = 1;
	}

	a = matrixSquared(a, n - m + 1);
	ll ans = 0;
	for (int i = 0; i < a[0].size(); i++)
		ans = ((ans % MOD) + (a[0][i] % MOD)) % MOD;
	printf("%lld", ans%MOD);

	return 0;
}

//#include <cstdio>
//#include <string>
//#include <vector>
//#include <algorithm>
//#define INF 987654321
//#define ll long long
//
//using namespace std;
//
//int binarysearch(vector<int> stones, ll left, ll right) {
//	if (left > right)return INF;
//	ll mid = (left + right) / 2;
//
//	if (mid >= stones.size() || stones[mid] > 0) {
//		return min(binarysearch(stones, left, mid - 1), (int)mid);
//	}
//
//	int k = binarysearch(stones, left, mid - 1);
//	if (k != INF)return k;
//	return binarysearch(stones, mid + 1, right);
//
//}
//
//int solution(vector<int> stones, int k) {
//	stones.push_back(INF);
//	int friends = 0, size = stones.size();
//
//	while (++friends) {
//		int cur = -1, next;
//
//		while (cur < size - 1) {
//			next = binarysearch(stones, cur + 1, cur + k);
//			if (next == INF)return friends - 1;
//			cur = next;
//			stones[cur]--;
//		}
//
//		if (cur != size - 1)break;	//이동할 수 있는 돌이 없음
//
//		//for (int i = 0; i < stones.size(); i++)
//		//	printf("%d ", stones[i] - cnt[i]);
//		//printf("\n");
//	}
//
//
//
//	return friends - 1;
//}
//
//int main() {
//	auto k = solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
//	printf("%d", k);
//}