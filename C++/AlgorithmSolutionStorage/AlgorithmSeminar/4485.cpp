#include <cstdio>
#include <queue>
#include <algorithm>
#define pip pair<int,point>
#define INF 987654321
using namespace std;

typedef struct { int x, y; }point;
int n, map[130][130], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

struct compare {
	bool operator()(pip a, pip b) {
		return a.first > b.first;
	}
};

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

int dijkstra() {
	int dist[130][130];
	bool visit[130][130] = { 0 };
	point start = { 0,0 }, fin = { n - 1,n - 1 };
	priority_queue<pip, vector<pip>, compare> pq;

	fill(&dist[0][0], &dist[n + 1][n], INF);
	dist[0][0] = map[0][0];
	pq.push(make_pair(dist[0][0],start));

	while (!pq.empty()) {
		pip p = pq.top(); pq.pop();
		point cur = p.second;
		if (visit[cur.y][cur.x])continue;

		visit[cur.y][cur.x] = 1;
		if (cur.x == fin.x && cur.y == fin.y)return dist[cur.y][cur.x];
		for (int i = 0; i < 4; i++) {
			int nx= cur.x + dx[i], ny=cur.y + dy[i];
			if (!safe(nx, ny) || visit[ny][nx])continue;
			if (dist[cur.y][cur.x] + map[ny][nx] < dist[ny][nx]) {
				dist[ny][nx]=dist[cur.y][cur.x] + map[ny][nx];
				point next = { nx,ny };
				pq.push(make_pair(dist[ny][nx], next));
			}
		}
	}
	return dist[fin.y][fin.x];
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc=0;
	while (++tc) {
		scanf("%d", &n);
		if (!n)break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);
		printf("Problem %d: %d\n",tc, dijkstra());
	}
	return 0;
}

//#include <cstdio>
//#include <queue>
//#include <vector>
//#define VERTEX 6
//#define INF 987654321
//using namespace std;
//
//int edge[VERTEX][VERTEX], e, u, v;
//bool visit[VERTEX];
//int dijkstra(int u, int v) {
//	vector<int> dist(VERTEX + 1, INF);
//	priority_queue<pair<int, int>> pq;
//
//	pq.push({ 0,u });
//	dist[u] = 0;
//	//출발점에서의 거리는 0
//
//	while (!pq.empty()) {
//		int cost = -pq.top().first;	//다음 최소 거리
//		int cur = pq.top().second;	//거리가 최소인 노드
//
//		pq.pop();
//
//		for (int next = 0; next < VERTEX; next++) {
//			if (!edge[cur][next])continue;
//			int ncost = edge[cur][next];
//
//			if (dist[cur] + ncost < dist[next]) {
//				dist[next] = dist[cur] + ncost;
//				pq.push({ -dist[next],next });
//				//거리가 작은 순으로 우선순위 부여
//			}
//			//거리 비교 후 최소값 갱신
//			
//		}
//	}
//	return dist[v];
//	//목적지 v로의 거리 반환
//}
//int main() {
//	scanf("%d%d", &u, &v);
//	scanf("%d", &e);
//	for (int i = 0, a, b, w; i < e; i++) {
//		scanf("%d%d%d", &a, &b, &w);
//		edge[a][b] = edge[b][a] = w;
//		//방향그래프일 경우 edge[b][a]에는 삽입하지 않으면 됨
//	}
//
//	printf("%d", dijkstra(u, v));
//	//u에서 v로의 최단경로 출력
//	return 0;
//}
//#include <cstdio>
//#include <queue>
//#include <algorithm>
//#define INF 987654321
//using namespace std;
//typedef struct { int x, y; }point;
//struct compare {
//	bool operator()(pair<int, point> a, pair<int, point> b) {
//		return a.first < b.first;
//	}
//};
//int main() {
//	int n, map[130][130], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//	priority_queue<pair<int, point>, vector<pair<int, point>>, compare> pq;
//	int k = 0;
//	while(++k){
//		scanf("%d", &n);
//		if (!n)return 0;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)scanf("%d", &map[i][j]);
//
//		int dist[130][130];
//		fill(&dist[0][0], &dist[n + 1][n], INF);
//
//		pq.push({ map[0][0],{0,0} });
//		dist[0][0] = map[0][0];
//
//		while (!pq.empty()) {
//			int cost = -pq.top().first;
//			point cur = pq.top().second;
//			pq.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = cur.x + dx[i], ny = cur.y + dy[i];
//				int ncost = map[ny][nx];
//				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
//				if (dist[cur.y][cur.x] + ncost < dist[ny][nx]) {
//					dist[ny][nx] = dist[cur.y][cur.x] + ncost;
//					pq.push({ -dist[ny][nx],{nx,ny} });
//				}
//			}
//		}
//		printf("Problem %d: %d\n",k,dist[n-1][n-1]);
//	}
//	return 0;
//}