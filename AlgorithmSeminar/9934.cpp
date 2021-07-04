#include <cstdio>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n,w[17][17],dp[16][65536];
int tsp(int cur,int visit) {
	if (visit == (1 << n) - 1)
		return w[cur][0] ? w[cur][0] : INF;
	int& ret = dp[cur][visit];
	if (ret != -1)return ret;

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i))continue;
		if (!w[cur][i])continue;
		ret = min(ret, tsp(i, visit | (1 << i)) + w[cur][i]);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
		scanf("%d", &w[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d", tsp(0, 1));
	return 0;
}
//#include <cstdio>
//int cbt[1030],building[1030],k,size,cnt;
//void traversal(int cur) {
//	if (cur * 2 + 1 < size)traversal(cur * 2 + 1);
//	cbt[cur] = building[cnt];
//	cnt++;
//	if (cur * 2 + 2 < size)traversal(cur * 2 + 2);
//}
//int main() {
//	scanf("%d", &k);
//	size = (1 << k)-1;
//	for (int i = 0; i < size; i++)scanf("%d", &building[i]);
//	traversal(0);
//	int t = 0;
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < (1 << i); j++)
//			printf("%d ", cbt[t++]);
//		printf("\n");
//	}
//	return 0;
//}