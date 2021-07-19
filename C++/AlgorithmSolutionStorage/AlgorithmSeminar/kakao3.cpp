#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

typedef struct { int cost, dep, num; }node;

struct compare {
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

int dijkstra(int n, int start, int end, vector<vector<int> >& map, vector<bool>& trap) {
	priority_queue<node, vector<node>, compare> pq;
	int status[1005][1005] = { 0 };
	int dist[1005][1005];
	bool visit[1005][1005] = { 0 };
	fill(&dist[0][0], &dist[1004][1004], INF);

	dist[0][start] = 0;
	visit[0][start] = 0;
	pq.push({ 0,0,start });

	while (!pq.empty()) {
		int cost = pq.top().cost, dep = pq.top().dep, cur = pq.top().num;
		pq.pop();
		if (cur == end)return cost;

		if (visit[dep][cur])continue;
		visit[dep][cur] = true;
		dep++;

		for (int i = 1; i <= n; i++) {
			if (trap[cur]) {
				status[cur][i] ^= 1;
				status[i][cur] ^= 1;
			}
			if (status[cur][i] == 0) {  //정방향
				if (map[cur][i] != INF && map[cur][i] + cost < dist[dep][i]) {
					dist[dep][i] = map[cur][i] + cost;
					pq.push({ dist[dep][i],dep,i });
				}
			}
			else {  //정방향
				if (map[i][cur] != INF && map[i][cur] + cost < dist[dep][i]) {
					dist[dep][i] = map[i][cur] + cost;
					pq.push({ dist[dep][i],dep,i });
				}
			}

		}
	}

	int m = INF;
	for (int i = 0; i < 1005; i++)m = min(m, dist[i][end]);
	return m;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = 0;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));
	vector<bool> tnode(n + 1, false);

	for (auto r : roads) {
		if(map[r[0]][r[1]]>r[2])
			map[r[0]][r[1]] = r[2];
	}
	for (auto t : traps)
		tnode[t] = true;

	return dijkstra(n, start, end, map, tnode);
}

int main() {
	//cout << solution(3, 1, 3, { {1,2,2},{3,2,3} }, { 2 });
	//cout << solution(4, 1, 4, { {1, 2, 1}, {3, 2, 1}, {2, 4, 1} }, { 2, 3 });
	cout << solution(4, 1, 4, { {1, 2, 1}, {2, 3, 1},{3, 2, 3}, {2, 4, 1} }, { 2, 3 });
}