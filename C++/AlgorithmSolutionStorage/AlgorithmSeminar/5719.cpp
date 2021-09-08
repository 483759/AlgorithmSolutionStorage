#include <cstdio>
#include <stack>
using namespace std;

void enqueue(stack<int>& s1, stack<int>& s2, int value) {
	s1.push(value);
}

int dequeue(stack<int>& s1, stack<int>& s2) {
	if (s1.empty() && s2.empty()) {
		printf("Queue is empty");
		return -1;
	}
	if (s2.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}

	int front = s2.top();
	s2.pop();
	return front;
}

int main() {
	stack<int> s1, s2;
	
	enqueue(s1, s2, 1);
	enqueue(s1, s2, 2);
	enqueue(s1, s2, 4);
	enqueue(s1, s2, 8);

	for (int i = 0; i < 4; i++) {
		int value = dequeue(s1, s2);
		printf("%d ", value);
	}
}

//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <vector>
//#define INF 500000001
//#define pii pair<int,int>
//using namespace std;
//
//int n, m, s, d;
//vector<vector<pii>> g;
//vector<vector<int>> prv;
//bool check[501][501];
//
//bool input() {
//	g.clear(); prv.clear();
//	scanf("%d%d", &n, &m);
//	if (!n && !m)return false;
//	memset(check, false, sizeof check);
//
//	scanf("%d%d", &s, &d);
//	g = vector<vector<pii>>(n + 1);
//
//	for (int i = 0, u, v, p; i < m; i++) {
//		scanf("%d%d%d", &u, &v, &p);
//		g[u].push_back(make_pair(p, v));
//	}
//	return true;
//}
//
//int dijkstra() {
//	vector<int> dist(n + 1, INF);
//	priority_queue<pii, vector<pii>, greater<>> pq;
//	prv = vector<vector<int>>(n + 1);
//
//
//	pq.push(make_pair(0, s));
//	dist[s] = 0;
//
//	while (!pq.empty()) {
//		int cur = pq.top().second;
//		int cost = pq.top().first; pq.pop();
//		if (cost > dist[cur])continue;
//
//		for (auto x : g[cur]) {
//			if (check[cur][x.second])continue;
//
//			int next = x.second;
//			int ncost = x.first;
//
//			if (dist[next] == dist[cur] + ncost) {
//				prv[next].push_back(cur);
//			}
//
//			if (dist[next] > dist[cur] + ncost) {
//				prv[next].clear();
//				prv[next].push_back(cur);
//				dist[next] = dist[cur] + ncost;
//				pq.push(make_pair(dist[next], next));
//			}
//		}
//	}
//
//	return dist[d] == INF ? -1 : dist[d];
//}
//
//void erase(int cur) {
//	for (auto x : prv[cur]) {
//		for (int i = 0; i < g[x].size(); i++) {
//			if (g[x][i].second == cur && !check[x][cur]) {
//				check[x][cur] = true;
//				erase(x);
//				break;
//			}
//		}
//	}
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	while (input()) {
//		dijkstra();
//		erase(d);
//		printf("%d\n", dijkstra());
//	}
//	return 0;
//}