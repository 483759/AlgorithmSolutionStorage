#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define pip pair<int,pii>
#define INF 987654321
using namespace std;

vector<vector<pii>> ds;
vector<vector<int>> ts;
vector<int> stationNum;
int n, m, t, k;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	ds = vector<vector<pii>>(n + 1);
	ts = vector<vector<int>>(n + 1);
	stationNum = vector<int>(n + 1);
	for (int i = 1, s; i <= n; i++) {
		scanf("%d", &stationNum[i]);
		ds[i] = vector<pii>(stationNum[i] + 1);
	}
	scanf("%d", &m);
	for (int i = 0, p1, p2, q1, q2; i < m; i++) {
		scanf("%d%d%d%d", &p1, &p2, &q1, &q2);
		ts[p1].push_back(p2);
		ts[q1].push_back(q2);
		ds[p1][p2] = make_pair(q1, q2);
		ds[q1][q2] = make_pair(p1, p2);
	}

	scanf("%d", &k);
	while (k--) {
		int u1, u2, v1, v2;

		scanf("%d%d%d%d%d", &t, &u1, &u2, &v1, &v2);

		vector<vector<int>> dist(n + 1);
		priority_queue<pip> pq;
		for (int i = 1; i <= n; i++) {
			dist[i] = vector<int>(stationNum[i] + 1, INF);
		}

		pq.push(make_pair(0, make_pair(u1, u2)));
		dist[u1][u2] = 0;

		while (!pq.empty()) {
			int cost = -pq.top().first;
			auto cur = pq.top().second; pq.pop();
			if (cost > dist[cur.first][cur.second])continue;

			for (auto x : ts[cur.first]) {
				auto des = ds[cur.first][x];
				if (dist[des.first][des.second] > dist[cur.first][cur.second] + abs(cur.second - x) + t) {
					dist[des.first][des.second] = dist[cur.first][cur.second] + abs(cur.second - x) + t;
					pq.push(make_pair(-dist[des.first][des.second], des));
				}
			}
			if (cur.first == v1) {
				if (dist[cur.first][v2] > dist[cur.first][cur.second] + abs(cur.second - v2)) {
					dist[cur.first][v2] = dist[cur.first][cur.second] + abs(cur.second - v2);
					pq.push(make_pair(-dist[cur.first][v2], make_pair(cur.first, v2)));
				}
			}

		}

		printf("%d\n", dist[v1][v2]);
	}

	return 0;
}