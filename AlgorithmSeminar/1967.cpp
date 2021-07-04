#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, dp[1000005];

int main() {
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int val[3] = { INF,INF,INF };
		if (i % 3 == 0)val[0] = dp[i / 3];
		if (i % 2 == 0)val[1] = dp[i / 2];
		val[2]= dp[i - 1];
		dp[i] = min({ val[0], val[1], val[2] })+1;
	}
	printf("%d", dp[n]);
	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef struct { int v, w; }node;
//int n,ans;
//vector<node> tree[10005];
//
//int dfs(int cur) {
//	if (tree[cur].size() == 0)return 0;
//	vector<int> max;
//
//	for (auto next : tree[cur]) {
//		max.push_back(next.w+dfs(next.v));
//	}
//	sort(max.begin(), max.end(),greater<>());
//
//	if (max.size() > 1&&(max[0] + max[1] > ans))ans = max[0] + max[1];
//	return max[0];
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++) {
//		int U,v,w;
//		scanf("%d", &U);
//		do {
//			scanf("%d", &v);
//			if (v == -1)break;
//			scanf("%d", &w);
//			tree[U].push_back({v,w});
//		} while (1);
//	}
//
//	int k=dfs(1);
//	if (k > ans)ans = k;
//	printf("%d", ans);
//	return 0;
//}