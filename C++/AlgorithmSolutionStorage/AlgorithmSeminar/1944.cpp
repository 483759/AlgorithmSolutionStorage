#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;

int m, n;
bool v[200001];
int dist[200001];
unsigned long all;
int main() {
	while (true) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)return 0;
		vector <pair<int, int>>* vertex = new vector<pair<int, int>>[m + 1];
		for (int i = 0; i < n; i++) {
			int x = 0;
			int y = 0;
			int z = 0;

			scanf("%d %d %d", &x, &y, &z);
			all += z;
			vertex[x].push_back(make_pair(y, z));
			vertex[y].push_back(make_pair(x, z));
		}

		for (int i = 0; i < m; i++) {
			dist[i] = INF;
		}
		dist[0] = 0;
		for (int cnt = 0; cnt < m-1; cnt++) {
			int mind = INF;
			int minIdx = 0;

			for (int i = 0; i < m; i++) {
				if ((dist[i] <= mind) && !v[i]) {
					mind = dist[i];
					minIdx = i;
				}
			}

			v[minIdx] = true;

			for (auto edge : vertex[minIdx]) {
				int check = edge.first;
				int w = edge.second;
				if (!v[check] && (w < dist[check])) {
					dist[check] = w;
				}
			}
		}
		unsigned long sum = 0;
		for (int i = 0; i < m; i++) {
			sum += dist[i];
		}
		printf("%d", all - sum);
	}
	return 0;
}

//#include <iostream>
//#include <queue>
//#include <string>
//#include <algorithm>
//#define INF 987654321
//#define pii pair<int,int>
//using namespace std;
//
//typedef struct { int x,y; }point;
////string map[51];
//int map[51][51];
//int n, m,dist[255][255];
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//vector<point> v;
//
//void bfs(point p) {
//	bool visit[51][51] = { 0 };
//	queue<point> q;
//
//	q.push({ p.x,p.y });
//	visit[p.y][p.x] = 1;
//	
//	int d = 0;
//	while (!q.empty()) {
//		int size = q.size();
//		for (int s = 0; s < size; s++) {
//			point cur = q.front(); q.pop();
//			if (map[cur.y][cur.x] > 0) {
//				dist[map[p.y][p.x]][map[cur.y][cur.x]] = d;
//			}
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.x + dx[i], ny = cur.y + dy[i];
//				if (map[ny][nx] == -1 || visit[ny][nx])continue;
//				q.push({ nx,ny });
//				visit[ny][nx] = 1;
//			}
//		}
//		d++;
//	}
//}
//
//int prim() {
//	priority_queue<pii, vector<pii>, greater<>> pq;
//	vector<int> cost(m + 2, INF);
//	vector<int> prev(m + 2, -1);
//	vector<bool> visit(m + 2, false);
//
//	int ans = 0;
//	pq.push(make_pair(0, 1));
//	cost[1] = 0;
//
//	while (!pq.empty()) {
//		pii cur = pq.top(); pq.pop();
//		if (visit[cur.second])continue;
//
//		visit[cur.second] = 1;
//		for (int i = 1; i <= m + 1; i++) {
//			if (dist[cur.second][i] != INF &&
//				(cost[i] > dist[cur.second][i])
//				&&!visit[i]) {
//				cost[i] = dist[cur.second][i];
//				prev[i] = cur.second;
//				pq.push(make_pair(cost[i], i));
//			}
//		}
//	}
//
//	for (int i = 1; i <= m + 1; i++) {
//		if (cost[i] == INF)return -1;
//		ans += cost[i];
//	}
//
//	return ans;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> n >> m;
//	int eNum = 2;
//	for (int i = 0; i < n; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < n; j++) {
//			switch (s[j]) {
//			case '1':
//				map[i][j] = -1;
//				break;
//			case '0':
//				map[i][j] = 0;
//				break;
//			case 'S':
//				map[i][j] = 1;
//				v.push_back({ j,i });
//				break;
//			default:
//				map[i][j] = eNum++;
//				v.push_back({ j,i });
//				break;
//			}
//		}
//	}
//
//	fill(&dist[0][0], &dist[m + 3][m + 2], INF);
//	for (int i = 0; i < v.size(); i++)
//		bfs(v[i]);
//
//	printf("%d", prim());
//	return 0;
//}