#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

vector<vector<pii>> g;
vector<vector<int>> dist;
int tc,n,m,k;

void dijkstra(int s) {
	dist[s] = vector<int>(n + 1, INF);
	priority_queue<pii,vector<pii>,greater<>> pq;

	dist[s][s] = 0;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cur = pq.top().second; 
		int cost = pq.top().first; pq.pop();
		if (cost > dist[s][cur])continue;

		for (auto x : g[cur]) 
		if(dist[s][x.second]>cost+x.first){
			dist[s][x.second] = x.first + cost;
			pq.push(make_pair(dist[s][x.second], x.second));
		}
	}
}

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d%d", &n, &m);
		g = vector<vector<pii>>(n + 1);
		dist = vector<vector<int>>(n + 1);

		for (int i = 0,a,b,c; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			g[a].push_back(make_pair(c, b));
			g[b].push_back(make_pair(c, a));
		}

		scanf("%d", &k);
		vector<int> f(k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &f[i]);
			dijkstra(f[i]);
		}

		int min = INF,ans;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++)
				if(!dist[j].empty()) sum += dist[j][i];
			if (sum < min) {
				min = sum;
				ans = i;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}