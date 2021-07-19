#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, s, p, ans,T;
vector<vector<int>> g;
vector<bool> visit;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d%d%d", &n, &s, &p);
	g = vector<vector<int>>(n + 1);
	priority_queue<int> pq;

	for (int i = 0, a, b; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	visit = vector<bool>(n + 1, false);
	for (int i = 1; i <= s; i++) {
		queue<int> q;

		q.push(i);
		visit[i] = 1;

		for (int time = 1, b = 1; b == 1; time++) {
			int size = q.size();
			while (size--) {
				int cur = q.front(); q.pop();
				if (cur == p) {
					pq.push(-time); b = 0; visit[cur] = 0;
					break;
				}

				for (auto x : g[cur]) {
					if (!visit[x]) {
						q.push(x); visit[x] = 1;
					}
				}

			}
		}
	}
	ans += -pq.top(); pq.pop();
	ans += -pq.top(); pq.pop();
	ans--;


	//for (int i = 1; i <= s; i++) {
	//	visit = vector<bool>(n + 1, false);
	//	queue<int> q;

	//	q.push(i);
	//	visit[i] = 1;

	//	for (int time = 1;; time++) {
	//		int size = q.size();
	//		if (!size)break;
	//		while (size--) {
	//			int cur = q.front(); q.pop();
	//			if (cur != i && cur <= s) {
	//				if (n - time > ans)ans = n - time;
	//			}

	//			for (auto x : g[cur]) {
	//				if (!visit[x]) {
	//					q.push(x); visit[x] = 1;
	//				}
	//			}

	//		}
	//	}
	//}
	printf("%d", n-ans);

	return 0;
}