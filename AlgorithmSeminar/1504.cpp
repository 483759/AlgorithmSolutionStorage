#include <cstdio>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int n, e,v1,v2;
vector<pair<int,int>> edge[805];
int dijkstra(int u, int v) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,u });
	dist[u] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second; pq.pop();

		for (auto x : edge[cur]) {
			if (dist[cur] + x.second < dist[x.first]) {
				dist[x.first] = dist[cur] + x.second;
				pq.push({ -dist[x.first],x.first });
			}
		}
	}
	return dist[v];
}
int main() {
	scanf("%d%d", &n, &e);
	for (int i = 0,a,b,c; i < e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	scanf("%d%d", &v1, &v2);
	int k = dijkstra(v1, v2);
	int s1 = dijkstra(1, v1) + k+ dijkstra(v2, n);
	int s2 = dijkstra(1, v2)+k+ dijkstra(v1,n);
	if (s1 < s2)
		printf("%d", (s1 >= INF ||s1<0)? -1 : s1);
	else printf("%d", (s2 >= INF||s2<0) ? -1 : s2);
	return 0;
}
//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//int dp[101][101],ans;
//int main() {
//	string a, b;
//	cin >>a>>b;
//	for (int i = 1; i <= a.length(); i++)
//		for (int j = 1; j <= b.length(); j++)
//			if (a[i-1] == b[j-1]) {
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				if (ans < dp[i][j])ans = dp[i][j];
//			}
//	printf("%d", ans);
//	return 0;
//}
//#include <string>
//#include <vector>
//
//using namespace std;
//vector<vector<int>> v;
//typedef struct { int x, y; }point;
//int N, ans;
//point dir[2][4] = { { {1,0},{-1,1},{0,1},{1,-1} },
//{{1,0},{1,-1},{0,1},{-1,1}} };
//bool safe(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
//void move(point cur, point des, int d, int k) {
//	while (!(cur.x == des.x && cur.y == des.y)) {
//		int nx = cur.x + dir[k][d].x;
//		int ny = cur.y + dir[k][d].y;
//		if (d % 2) {
//			while (safe(nx, ny)) {
//				ans += 2;
//				cur = { nx,ny }; v[cur.y][cur.x] = ans;
//				nx += dir[k][d].x;
//				ny += dir[k][d].y;
//			}
//		}
//		else {
//			ans++;
//			cur = { nx,ny }; v[cur.y][cur.x] = ans;
//		}
//		d = (d + 1) % 4;
//	}
//}
//
//vector<vector<int>> solution(int n, bool horizontal) {
//	v.resize(n); N = n;
//	for (int i = 0; i < n; i++)v[i].resize(n);
//
//	if (n % 2) {
//		if (horizontal) {
//			move({ 0,0 }, { n - 1,0 }, 0, 0);
//			move({ n - 1,0 }, { n - 1,n - 1 }, 2, 1);
//		}
//		else {
//			move({ 0,0 }, { 0,n - 1 }, 2, 0);
//			move({ 0,n - 1 }, { n - 1,n - 1 }, 0, 1);
//
//		}
//	}
//	else {
//		if (horizontal) {
//			move({ 0,0 }, { 0,n - 1 }, 0, 0);
//			move({ 0,n - 1 }, { n - 1,n - 1 }, 0, 1);
//		}
//		else {
//			move({ 0,0 }, { n - 1,0 }, 2, 0);
//			move({ n - 1,0 }, { n - 1,n - 1 }, 2, 1);
//
//		}
//	}
//	return v;
//}
//
//int main() {
//	vector<vector<int>> v=solution(9, 0);
//		for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v[i].size(); j++)
//			printf("%6d", v[i][j]);
//		printf("\n");
//	}
//	return 0;
//}

//#include <cstdio>
//#include <vector>
//using namespace std;
//typedef struct { int x, y; }point;
//point dir[2][4] = { { {1,0},{-1,1},{0,1},{1,-1} },
//{{1,0},{1,-1},{0,1},{-1,1}} };
//int n=4,ans;
//vector<vector<int>> v(n);
//bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
//void move(point cur,point des,int d,int k) {
//	while (!(cur.x == des.x && cur.y == des.y)) {
//		int nx = cur.x + dir[k][d].x;
//		int ny = cur.y + dir[k][d].y;
//		if (d % 2) {
//			while (safe(nx, ny)) {
//				ans += 2;
//				cur = { nx,ny }; v[cur.y][cur.x] = ans;
//				nx += dir[k][d].x;
//				ny += dir[k][d].y;
//			}
//		}
//		else {
//			ans++;
//			cur = { nx,ny }; v[cur.y][cur.x] = ans;
//		}
//		d = (d + 1) % 4;
//	}
//}
//int main() {
//	for (int i = 0; i < n; i++)v[i].resize(n);
//	point cur = { 0,0 }; int d = 0,h=0;
//	//while (!(cur.x == 0 && cur.y == n - 1)) {
//	//	int nx = cur.x + dir[0][d].x;
//	//	int ny = cur.y + dir[0][d].y;
//	//	if (d % 2) {
//	//		while (safe(nx, ny)) {
//	//			ans += 2;
//	//			cur = { nx,ny }; v[cur.y][cur.x] = ans;
//	//			nx += dir[0][d].x;
//	//			ny += dir[0][d].y;
//	//		}
//	//	}
//	//	else {
//	//		ans++;
//	//		cur = { nx,ny }; v[cur.y][cur.x] = ans;
//	//	}
//	//	d = (d + 1) % 4;
//	//}
//	//move({ 0,0 }, { 0,n - 1 }, 0, 0);
//	//move({ 0,n - 1 }, { n - 1,n - 1 }, 0, 1);
//
//	if (n % 2) {
//		if (h) {
//			move({ 0,0 }, { n - 1,0 }, 0, 0);
//			move({ n - 1,0 }, { n - 1,n - 1 }, 0, 1);
//		}
//		else {
//			move({ 0,0 }, {0,n-1 }, 2, 0);
//			move({ 0,n - 1 }, { n - 1,n - 1 }, 2, 1);
//
//		}
//	}
//	else{
//		if (h) {
//			move({ 0,0 }, { 0,n - 1 }, 0, 0);
//			move({ 0,n - 1 }, { n - 1,n - 1 }, 0, 1);
//		}
//		else {
//			move({ 0,0 }, { n - 1,0 }, 2, 0);
//			move({ n - 1,0 }, { n - 1,n - 1 }, 2, 1);
//
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			printf("%3d", v[i][j]);
//		printf("\n");
//	}
//	return 0;
//}
//#include <cstdio>
//#include <queue>
//#include <vector>
//using namespace std;
//typedef struct { int x, y; }point;
//int n, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//point p;
//int bfs(vector<vector<int>> map,int num) {
//	int visit[31][31] = { 0 };
//	queue<point> q;
//
//	q.push(p);
//	visit[p.y][p.x] = 1;
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		if (map[cur.y][cur.x] == num) {
//			p = { cur.x,cur.y };
//			return visit[cur.y][cur.x];
//		}
//		for (int i = 0; i < 4; i++) {
//			int nx = (cur.x + dx[i] + n) % n;
//			int ny = (cur.y + dy[i] + n) % n;
//			if (visit[ny][nx])continue;
//			q.push({ nx,ny });
//			visit[ny][nx] = visit[cur.y][cur.x] + 1;
//		}
//	}
//}
//int main() {
//	n = 4;
//	int answer = 0;
//	vector<vector<int>> v = { {11, 9, 8, 12}, {2, 15, 4, 14}, {1, 10, 16, 3}, {13, 7, 5, 6} };
//	for (int i = 1; i <= n * n; i++)
//		answer += bfs(v,i);
//	printf("%d", answer);
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//#define INF 987654321
//using namespace std;
//int n, e,edge[805][805],v1,v2;
//int dijkstra(int u, int v) {
//	int dist[805];
//	priority_queue<pair<int,int>> pq;
//	fill(&dist[0], &dist[n + 1], INF);
//
//	dist[u] = 0;
//	pq.push({ 0,u });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//
//		for (int i = 1; i <= n; i++) {
//			if (!edge[cur][i])continue;
//			int ncost = edge[cur][i];
//
//			if (dist[cur] + ncost < dist[i]) {
//				dist[i] = dist[cur] + ncost;
//				pq.push({ -dist[i],i });
//			}
//		}
//	}
//
//
//}
//int main() {
//	scanf("%d%d", &n, &e);
//	for (int i = 0,a,b,c; i < e; i++) {
//		scanf("%d%d%d", &a, &b, &c);
//		edge[a][b] = edge[b][a] = c;
//	}
//	scanf("%d%d", &v1, &v2);
//	return 0;
//}