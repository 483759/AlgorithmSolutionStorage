#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n,graph[505][505];
vector<int> arr = { 0 }, indeg,time;
queue<int> q;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	indeg = vector<int>(n + 1,0);
	time = vector<int>(n + 1, 100001 * 501);
	for (int i = 1; i <= n; i++) {
		for (int j = 0,k;; j++) {
			scanf("%d", &k);
			if (k == -1)break;

			if (j == 0)arr.push_back(k);
			else {
				graph[k][i] = 1;
				indeg[i]++;
			}
		}
		if (indeg[i] == 0)graph[0][i] = 1;
	}

	time[0] = 0;
	for (int i = 1; i <= n; i++)
		if (!indeg[i])q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		int max = 0;
		for (int i = 0; i <= n; i++) {
			if (graph[i][cur]) {
				max = time[i] > max ? time[i] : max;
			}
		}
		time[cur] = max + arr[cur];
		for (int i = 1; i <= n; i++) {
			if (graph[cur][i] && indeg[i]) {
				indeg[i]--;
				if (!indeg[i])q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", time[i]);
	return 0;
}