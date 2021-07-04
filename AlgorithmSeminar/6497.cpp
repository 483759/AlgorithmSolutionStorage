#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;
int tc;
int main() {
	while (1) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)break;
		vector<vector<pii>> graph(n);

		int sum = 0;
		for (int i = 0,x,y,z; i < m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			graph[x].push_back({ z,y });
			graph[y].push_back({ z,x });
			sum += z;
		}

		vector<int> cost(n,INF);
		vector<int> prev(n, -1);
		vector<bool> visit(n, false);
		priority_queue<pii, vector<pii>, greater<>> pq;

		pq.push({ 0,0 });
		cost[0] = 0;

		while (!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			if (visit[cur.second])continue;

			sum -= cur.first;
			visit[cur.second] = true;
			for (auto x : graph[cur.second]) {
				if (!visit[x.second] && (cost[x.second] > x.first)) {
					pq.push(x);
					cost[x.second] = x.first;
					prev[x.second] = cur.second;
				}

			}
		}

		printf("%d\n", sum);
		
	}
	return 0;
}