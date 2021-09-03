#include <cstdio>
#include <algorithm>
using namespace std;

int T, W;
int plum[1005], cache[2][31][1005];

int dp(int l, int w, int t) {
	if (t == 0)return 0;

	int& ref = cache[l][w][t];
	if (ref != -1)return ref;

	ref = 0;
	if (l == plum[t]) {
		ref = dp(l, w, t - 1) + 1;
	}
	else {
		if (w > 0) {
			ref = dp(!l, w - 1, t - 1) + 1;
		}
	}

	return ref;
}

int func(int time, int w, int cur) {
	if ((time > T) || (w > W)) {
		return 0;
	}
	int& ref = cache[cur][w][time];
	if (ref != -1)return ref;

	ref = 0;
	if (cur == plum[time])
		ref = max(func(time + 1, w, cur), func(time + 1, w + 1, !cur)) + 1;
	else {
		ref = func(time + 1, w, cur);
		if (w < W)
			ref = max(ref, func(time + 1, w + 1, !cur) + 1);
	}
	//else
	return ref;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &T, &W);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &plum[i]);
		if (plum[i] == 2)plum[i] = 0;
	}
	fill(&cache[0][0][0], &cache[1][30][T + 1], -1);

	//int ans = 0;
	//for (int i = 0; i <= W; i++)
	//	ans = max({ ans, dp(0, i, T), dp(1, i, T) });
	//	

	//printf("%d", ans);
	printf("%d", func(1, 0, 1));
	return 0;
}