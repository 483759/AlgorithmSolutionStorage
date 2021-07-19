#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int s, dp[2005];

int main() {
	scanf("%d", &s);
	fill(&dp[0], &dp[s * 2+3], INF);
	dp[0] = dp[1] = 0;

	for (int i = 1; i <= 2 * s; i++) {
		for (int j = 2; i * j <= 2*s; j++)
			dp[i * j] = min(dp[i * j],dp[i] + j);
		for (int j = 2 * s - 1; j >= 2; j--)
			dp[j] = min(dp[j], dp[j + 1] + 1);
	}

	for (int i = 1; i <= 2 * s; i++)
		printf("%2d ", i);
	printf("\n");
	for (int i = 1; i <= 2*s; i++)
		printf("%2d ", dp[i]);

	printf("\n%d", dp[s]);

	return 0;
}

//#include <cstdio>
//#include <queue>
//#define pii pair<int,int>
//#define fi first
//#define se second
//using namespace std;
//
//queue<pii> q;
//int s;
//bool visit[2005][2005];
//
//int main() {
//	scanf("%d", &s);
//	q.push(make_pair(1, 0));
//	visit[1][0] = true;
//
//	int ans = 0;
//	while (!q.empty()) {
//		int size = q.size();
//		while (size--) {
//			auto cur = q.front(); q.pop();
//
//			if (cur.first == s) {
//				for(int i=1;i<=s;i++)
//					printf("%d ",)
//				printf("%d", ans);
//				return 0;
//			}
//
//			if (!visit[cur.fi][cur.fi]) {
//				q.push(make_pair(cur.fi, cur.fi));
//				visit[cur.fi][cur.fi] = true;
//			}
//			if (cur.se &&(cur.fi +cur.se <2000) && !visit[cur.fi + cur.se][cur.se]) {
//				q.push(make_pair(cur.fi + cur.se, cur.se));
//				visit[cur.fi + cur.se][cur.se] = true;
//			}
//			if (cur.fi > 0 && !visit[cur.fi - 1][cur.se]) {
//				q.push(make_pair(cur.fi - 1, cur.se));
//				visit[cur.fi - 1][cur.se] = true;
//			}
//		}
//		ans++;
//	}
//	return 0;
//}